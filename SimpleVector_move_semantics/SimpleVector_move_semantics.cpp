#include <iostream>
#include "SimpleVector_move_semantics.h"

// constructor
template < class T >
SimpleVector_Move<T> :: SimpleVector_Move() noexcept {

    this->size = 0;
    this->arr = new T[this->size];
    this->temp_arr = new T[this->size];

}

// destructor
template < class T >
SimpleVector_Move<T> :: ~SimpleVector_Move() noexcept {

    delete[] this->arr;

    std::cout << "The destructor was invoked here" << std::endl;

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

    *(this->arr + this->size) = element;
     this->size = this->size + 1;

}

// pop_back function to remove the last element added to the array
template < class T >
void SimpleVector_Move<T> :: pop_back() {

    if(this->size > 0) {
       this->size = this->size - 1;

       this->temp_arr = new T[this->size];

       for(int x = 0; x < this->size; x++) {
            *(this->temp_arr + x) = *(this->arr + x);
       }

       delete[] arr;
       this->arr = this->temp_arr;
       this->temp_arr = nullptr;
    }

}

// check if the array is empty return true: array is empty OR false: otherwise
template < class T >
bool SimpleVector_Move<T> :: isEmpty() {

    if(this->size == 0) {
        return true;
    }

    return false;

}

// Get the size of the array
template < class T >
int SimpleVector_Move<T> :: getSize() {
    
    return this->size;
}

// remove all elements from the current array
template < class T >
void SimpleVector_Move<T> :: clear() {

    delete[] this->arr;
    this->arr = nullptr;
    this->size = 0;

}

// overload the [] operator: return the value at a specific index in the array
template < class T >
T& SimpleVector_Move<T> :: operator[](const int& index) {

    if(index >= 0 && index < this->size) {
        return *(this->arr + index);
    }

    std::cerr << "index "<< index << " is out of range" << std::endl;
    std::exit(EXIT_FAILURE);
}