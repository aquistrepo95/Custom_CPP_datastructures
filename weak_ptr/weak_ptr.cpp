#include <iostream>
#include "weak_ptr.h"
#include "shared_ptr.h"


// compile time constructor
template < class T >
constexpr weak_ptr<T> :: weak_ptr() noexcept {
   
    weak_pointer   = nullptr;
    weak_cb        = nullptr;

}

// constructor for shared_ptr object
template < class T >
weak_ptr<T> :: weak_ptr(const shared_ptr<T>& shared_ptr) {

    weak_pointer = shared_ptr.shared_pointer;
    weak_cb      = shared_ptr.shared_cb;

    if(weak_pointer) {
        weak_cb->weak_ref_count++;
    }
}

// assginment operator for shared_ptr object
template < class T >
weak_ptr<T>& weak_ptr<T> :: operator=(const shared_ptr<T>& shared_ptr) {

        reset();
        weak_pointer = shared_ptr.shared_pointer;
        weak_cb      = shared_ptr.shared_cb;

        if(weak_pointer) {
            weak_cb->weak_ref_count++;
        }

    return *this;

}

// destructor
template < class T >
weak_ptr<T> :: ~weak_ptr() {

    reset();

    std::cout << "The destructor for the weak_ptr was invoked" << std::endl;
}

// copy constructor
template < class T >
weak_ptr<T> :: weak_ptr(const weak_ptr<T>& obj) {

    this->weak_pointer = obj.weak_pointer;
    this->weak_cb      = obj.weak_cb;

    if(this->weak_pointer) {
        this->weak_cb->weak_ref_count++;
    }
}

// copy assignment operator
template < class T >
weak_ptr<T>& weak_ptr<T> :: operator=(const weak_ptr<T>& obj) {

    if(this != &obj) {
        reset();

        this->weak_pointer = obj.weak_pointer;
        this->weak_cb      = obj.weak_cb;

        if(this->weak_pointer) {
            this->weak_cb->weak_ref_count++;
        }
    }

    return *this; 
}

// member functions
// reset() function: releases the reference to the managed resource
template < class T >
void weak_ptr<T> :: reset() noexcept {

   if(weak_cb->weak_ref_count > 0) {
        weak_cb->weak_ref_count--;
   } 

   weak_cb = nullptr;
   weak_pointer = nullptr;
}

// swap() function: swap weak_ptr objects
template < class T >
void weak_ptr<T> :: swap(weak_ptr<T>& obj) noexcept {

    if(this != &obj) {
        T* temp_pointer = nullptr;
        // swap weak pointers
        temp_pointer         = this->weak_pointer;
        this->weak_pointer   = obj.weak_pointer;
        obj.weak_pointer     = temp_pointer;

        control_block* temp = nullptr;

        // swap control blocks
        temp             = this->weak_cb;
        this->weak_cb    = obj.weak_cb;
        obj.weak_cb      = temp;
        
    }
}

// use_count function: eturns the number of weak_ptr object managing a resource
template < class T >
int weak_ptr<T> :: use_count() const noexcept {

    return weak_cb ? weak_cb->strong_ref_count : 0;
}

// expired() function: verify if the current resource was already deleted
template < class T >
bool weak_ptr<T> :: expired() const noexcept {

    if(use_count() == 0) {
        return true;
    }
    else {
        return false;
    }
}

// lock() function: create a shared_ptr object for a weak_ptr
template < class T >
shared_ptr<T> weak_ptr<T> :: lock() const noexcept {
    if(expired()) {
        return shared_ptr<T>();
    }

    else {
        return shared_ptr<T>(weak_pointer, weak_cb);
    }

}