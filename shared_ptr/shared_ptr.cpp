#include <iostream>
#include "shared_ptr.h"

//compile time constructor
template < class T >
constexpr shared_ptr<T> :: shared_ptr() noexcept {

    T* pointer    = nullptr;
    T* ref_count  = nullptr;

}

// constructor: accepts a raw pointer from heap memory allocation and assigns it to the define pointer in the class
template < class T >
shared_ptr<T> :: shared_ptr(T* raw_pointer) {

    if(raw_pointer != nullptr) {
        this->pointer   = raw_pointer;
        this->ref_count = new int(1);
    }    

    std::cout << "constructor was invoked" << std::endl;

}

// destructor
template < class T >
shared_ptr<T> :: ~shared_ptr() noexcept {

    reset();

    std::cout << "The destructor was invoked" << std::endl;

}

//copy constructor
template < class T >
shared_ptr<T> :: shared_ptr(const shared_ptr& obj) {
    
    this->pointer   = obj.pointer;
    this->ref_count = obj.ref_count;

    if(this->ref_count) {
        (*this->ref_count)++;
    }

}

//copy assignment
template < class T >
shared_ptr<T>& shared_ptr<T> :: operator=(const shared_ptr& obj) {

    if(this != &obj) {
        reset();

        this->pointer   = obj.pointer;
        this->ref_count = obj.ref_count;

        if(this->ref_count){
            (*this->ref_count)++;
        }
    }

    return *this;
}

// move constructor
template < class T >
shared_ptr<T> :: shared_ptr(shared_ptr&& obj) noexcept {

    this->pointer   = obj.pointer;
    this->ref_count = obj.ref_count;

    obj.pointer   = nullptr;
    obj.ref_count = nullptr;

}

// move assignment
template < class T >
shared_ptr<T>& shared_ptr<T> :: operator=(shared_ptr&& obj) noexcept {

    if(this != &obj) {
        reset();

        this->pointer   = obj.pointer;
        this->ref_count = obj.ref_count;

        obj.pointer   = nullptr;
        obj.ref_count = nullptr;
    }

    return *this;

}

// member functions
// get() member function to return a pointer of the resource
template < class T >
T* shared_ptr<T> :: get() const noexcept {

    return this->pointer;

}

// reset() member function to replace the managed resource
template < class T >
void shared_ptr<T> :: reset(T* new_pointer /* default parameter */) noexcept {

    if(this->ref_count) {
        (*this->ref_count)--;

        if((*this->ref_count) == 0) {
            delete this->pointer;
            delete this->ref_count;
        }

        else {
            this->ref_count = nullptr;
        }
    }

    this->pointer = new_pointer;

    if(new_pointer) {
        this->ref_count = new int(1);
    }

}

// swap() member function to swap managed resources
template < class T >
void shared_ptr<T> :: swap(shared_ptr& obj) noexcept {

    if(this != &obj) {
        T* temp_pointer = this->pointer;
        this->pointer   = obj.pointer;
        obj.pointer     = temp_pointer;
    } 

}

// use_count() member function to return the number of shared_ptr objects pointin to the same resource
template < class T >
int shared_ptr<T> :: use_count() const noexcept {

    return *this->ref_count;

}

// unique() member function to verify if the current resource is managed by only one pointer 
template < class T >
bool shared_ptr<T> :: unique() const noexcept {

    if((*this->ref_count) == 1) {
        return true;
    }

    else {
        return false;
    }

}

// Operator overloading
// overloading the indirection operator
template < class T >
T& shared_ptr<T> :: operator*() const noexcept {

    return *this->pointer;

}

// overloading the arrow operator
template < class T >
T* shared_ptr<T> :: operator->() const noexcept {

    return this->pointer;

}