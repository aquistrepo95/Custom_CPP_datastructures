#include <iostream>
#include "unique_ptr.h"

// compile time constructor
template < class T >
constexpr unique_ptr<T> :: unique_ptr() noexcept {

    pointer = nullptr;

}

// constructor: accepts a raw pointer from heap memory allocation and assigns it to the define pointer in the class
template < class T >
unique_ptr<T> :: unique_ptr(T* raw_ptr) noexcept {

    pointer = raw_ptr;

    std::cout << "constructor was invoked" << std::endl;
}

// destructor
template < class T >
unique_ptr<T> :: ~unique_ptr() {

    reset();

    std::cout << "The destructor was invoked" << std::endl;
}

// move constructor
template < class T >
unique_ptr<T> :: unique_ptr(unique_ptr&& obj) noexcept {

    this->pointer = obj.pointer;
    obj.pointer = nullptr;

}

// move assignment operator
template < class T >
unique_ptr<T>& unique_ptr<T> :: operator=(unique_ptr&& obj) noexcept {

    if(this != &obj) {
        
        delete this->pointer;
        this->pointer = obj.pointer;
        obj.pointer = nullptr;
    }

    return *this;
}

// get() member function to return a pointer to a managed resource
template < class T >
T* unique_ptr<T> :: get() const noexcept {

    return pointer;
}

// release() member function to release ownership and return a pointer to a managed resource
template < class T >
T* unique_ptr<T> :: release() noexcept {

    T* old_pointer = pointer;
    pointer = nullptr;
    return old_pointer;

}

// reset() member function to replace a managed resource
template < class T >
void unique_ptr<T> :: reset(T* new_pointer /* new_pointer is set to nullptr*/) noexcept {
     
     if(pointer != nullptr) {
        delete pointer; 
     }

     pointer = new_pointer;   
}

// swap() member function to swap a managed resource for another
template < class T >
void unique_ptr<T> :: swap(unique_ptr& obj) noexcept {

    T* temp_pointer = this->pointer;
    this->pointer   = obj.pointer;
    obj.pointer    = temp_pointer;

}

// overload the indirection oprator(*)
template < class T >
T& unique_ptr<T> :: operator*() const noexcept {

    return *pointer;

}

// overload the arrow operator(->)
template < class T >
T* unique_ptr<T> :: operator->() const noexcept {

    return pointer;

}
