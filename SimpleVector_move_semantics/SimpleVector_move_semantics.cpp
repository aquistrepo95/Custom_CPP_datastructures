#include <iostream>
#include "SimpleVector_move_semantics.h"

// constructor
template < class T >
SimpleVector_Move<T> :: SimpleVector_Move() {

    size = 0;
    arr = new T[size];
    temp_arr = new T[size];

}

// destructor
template < class T >
SimpleVector_Move<T> :: ~SimpleVector_Move() noexcept {

    delete[] arr;

    std::cout << "The destructor was invoked here" << std::endl;

}

// copy constructor
template < class T >
SimpleVector_Move<T> :: SimpleVector_Move(const SimpleVector_Move& obj) {
    
    this->size = obj.size;
    this->arr  = new T[this->size];

    for(int x = 0; x < this->size; x++) {
        *(this->arr + x) = *(obj.arr + x);
    }
}

// copy assignment operator
template < class T >
SimpleVector_Move<T>& SimpleVector_Move<T> :: operator=(const SimpleVector_Move& obj) {
   
    if(this == &obj) {
        return *this;
    }
        
    delete[] this->arr;
    this->size = 0;

    this->size = obj.size;
    this->arr  = new T[this->size];

    for(int x = 0; x < this->size; x++) {
        *(this->arr + x) = *(obj.arr + x);
    }

    return *this;

}

// move constructor
template < class T >
SimpleVector_Move<T> :: SimpleVector_Move(SimpleVector_Move&& obj) noexcept{

    this->arr  = obj.arr;
    this->size = obj.size;

    std::cout << "Arraysize from move constructor: " << this->size << std::endl;

    obj.arr = nullptr; 
    obj.size = 0;
}

// move assigmnet operator
template < class T >
SimpleVector_Move<T>& SimpleVector_Move<T> :: operator=(SimpleVector_Move&& obj) noexcept{
    if(this != &obj) {

        delete[] this->arr;
        this->size = 0;

        this->arr  = obj.arr;
        this->size = obj.size;
        std::cout << "Arraysize from move assignment: " << this->size << std::endl;

        obj.arr = nullptr;
        obj.size = 0;
    }

    return *this;
}

// push_back function to add new element to the current array
template < class T >
void SimpleVector_Move<T> :: push_back(const T& element) {

    *(arr + size) = element;
     size = size + 1;

}

// pop_back function to remove the last element added to the array
template < class T >
void SimpleVector_Move<T> :: pop_back() {

    if(size > 0) {
       size = size - 1;

       temp_arr = new T[size];

       for(int x = 0; x < size; x++) {
            *(temp_arr + x) = *(arr + x);
       }

       delete[] arr;
       arr = temp_arr;
       temp_arr = nullptr;
    }

}

// check if the array is empty return true: array is empty OR false: otherwise
template < class T >
bool SimpleVector_Move<T> :: isEmpty() const noexcept {

    if(size == 0) {
        return true;
    }

    return false;

}

// Get the size of the array
template < class T >
int SimpleVector_Move<T> :: getSize() const noexcept {
    
    return size;
}

// remove all elements from the current array
template < class T >
void SimpleVector_Move<T> :: clear() {

    delete[] arr;
    arr = nullptr;
    size = 0;

}

// overload the [] operator: return the value at a specific index in the array
template < class T >
T& SimpleVector_Move<T> :: operator[](const int& index) {

    if(index >= 0 && index < size) {
        return *(arr + index);
    }

    std::cerr << "index "<< index << " is out of range" << std::endl;
    std::exit(EXIT_FAILURE);
}