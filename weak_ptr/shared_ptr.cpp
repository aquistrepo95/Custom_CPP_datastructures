#include "shared_ptr.h"
#include "weak_ptr.h"
#include <iostream>


// compile time constructor
template < class T >
constexpr shared_ptr<T> :: shared_ptr() noexcept {
   
    shared_pointer  = nullptr;
    shared_cb       = nullptr;

}

// constructor
template < class T >
constexpr shared_ptr<T> :: shared_ptr(T* raw_pointer) {

    this->shared_pointer = raw_pointer;

    if(this->shared_pointer) {
        this->shared_cb      = new control_block();
        this->shared_cb->strong_ref_count++;
    } 

}

// constructor overload for lock() function to create a shared_ptr object
template < class T >
shared_ptr<T> :: shared_ptr(T* weak_pointer, control_block* weak_cb) {

        shared_pointer = weak_pointer;
        shared_cb      = weak_cb;

        if(shared_pointer) {
            shared_cb->strong_ref_count++;
        }
}

// destructor
template < class T >
shared_ptr<T> :: ~shared_ptr() {

    //std::cout << "destroying: " << shared_pointer << " : " << shared_cb << std::endl;

    if(shared_pointer != 0 && shared_cb != 0) {
        std::cout << "destroying: " << shared_pointer << " : " << shared_cb << std::endl;
        reset();
        std::cout << "The destructor for the shared_ptr was invoked" << std::endl;
    }

}

// copy constructor
template < class T >
shared_ptr<T> :: shared_ptr(const shared_ptr& obj) {

    this->shared_pointer   = obj.shared_pointer;
    this->shared_cb        = obj.shared_cb;

    if(this->shared_cb) {
        this->shared_cb->strong_ref_count++;
    } 

}

// copy assignment operator
template < class T >
shared_ptr<T>& shared_ptr<T> :: operator=(const shared_ptr& obj) {

    if(this != &obj) {
        reset();

        this->shared_pointer   = obj.shared_pointer;
        this->shared_cb        = obj.shared_cb;

        if(this->shared_cb) {
            this->shared_cb->strong_ref_count++;
        }

    }

    return *this;

}

// move constructor
template < class T >
shared_ptr<T> :: shared_ptr(shared_ptr&& obj) noexcept{

    this->shared_pointer  = obj.shared_pointer;
    this->shared_cb       = obj.shared_cb;

    obj.shared_pointer = nullptr;
    obj.shared_cb      = nullptr;
    
}

// move assignment operator
template < class T >
shared_ptr<T>& shared_ptr<T> :: operator=(shared_ptr&& obj) noexcept {
    
    if(this != &obj) {
        reset();

        this->shared_pointer   = obj.shared_pointer;
        this->shared_cb        = obj.shared_cb;

        obj.shared_pointer = nullptr;
        obj.shared_cb      = nullptr;

    }

    return *this;

}

// member functions
// get() function: return a pointer to the managed resource
template < class T >
T* shared_ptr<T> :: get() const noexcept {

    return shared_pointer;

}

// reset() function: release the ownership of the managed resource
template < class T >
void shared_ptr<T> :: reset(T* new_pointer /* default parameter */) noexcept { //will come back here

    if(shared_cb->strong_ref_count > 0) {
        shared_cb->strong_ref_count--;

        if(shared_cb->strong_ref_count == 0) {
            delete shared_pointer;
            delete shared_cb;
        }
        
    }

    if(shared_cb->strong_ref_count > 0) { // check this
        shared_cb = nullptr;
    }

    shared_pointer = new_pointer;

    if(new_pointer != nullptr) { //check this
        if(shared_cb == nullptr){
            shared_cb  = new control_block();
            shared_cb->strong_ref_count++;
        }
    }

}

// swap() function: swap managed resources
template < class T >
void shared_ptr<T> :: swap(shared_ptr& obj) noexcept {

    if(this != &obj) {
        T* temp_pointer = nullptr;
        // swap shared pointers
        temp_pointer         = this->shared_pointer;
        this->shared_pointer = obj.shared_pointer;
        obj.shared_pointer   = temp_pointer;

        control_block* temp = nullptr;

        // swap control blocks
        temp             = this->shared_cb;
        this->shared_cb  = obj.shared_cb;
        obj.shared_cb    = temp;
        
    }
}

// use_count() function: returns the number of shared_ptr object managing a resource
template < class T >
int shared_ptr<T> :: use_count() const noexcept {

    return shared_cb ? shared_cb->strong_ref_count : 0;

}

// unique() function: verify if the current resource is managed only by the current shared_ptr object
template < class T >
bool shared_ptr<T> :: unique() const noexcept {

    if(shared_cb->strong_ref_count == 1) {
        return true;
    }

    else {
        return false;
    }

}

// operator overloading
// overload the * operator
template < class T >
T& shared_ptr<T> :: operator*() const noexcept {

    return *shared_pointer;
}

// overload the -> operator
template < class T >
T* shared_ptr<T> :: operator->() const noexcept {

    return shared_pointer;

}