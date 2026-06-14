#include <iostream>
#include "SimpleVector.h"

// constructor
template< class T >
SimpleVector<T> :: SimpleVector() {

    this->size = 0;
    this->arr = new T[this->size];
    this->temp_arr = new T[this->size];

}

// destructor
template< class T >
SimpleVector<T> :: ~SimpleVector() {

    delete[] this->arr;

    std::cout << "The destructor was invoked here" << std::endl;

}

// Copy constructor(create new object from existing object)
template< class T >
SimpleVector<T> :: SimpleVector(const SimpleVector& obj) {

    this->size = obj.size;
    std::cout << "obj.size is: " << obj.size << std::endl;
    this->arr  = new T[this->size];

    for(int x = 0; x < this->size; x++) {
        *(this->arr + x) = *(obj.arr + x);
    }

}

// Copy assignment(copy contents of existing objects to content of another existing object)
template< class T >
SimpleVector<T>& SimpleVector<T> :: operator=(const SimpleVector& obj) {
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

// push new element into array
template < class T >
void SimpleVector<T> :: push_back(T element) {

    *(this->arr + this->size) = element;
     this->size = this->size + 1;

}

// remove last element from the array
template < class T >
void SimpleVector<T> :: pop_back() {

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

// Check if the array is empty
template < class T >
bool SimpleVector<T> :: isEmpty() {
    if(this->size == 0) {
        return true;
    }

    return false;
}

// Get the size of the array
template < class T >
int SimpleVector<T> :: getSize() {

    return this->size;

}

// overload the [] operator: return the value at a specific index in the array
template < class T >
T& SimpleVector<T> :: operator[](const int& index) {

    if(index >= 0 && index < this->size) {
        return *(arr + index);
    }

    std::cerr << "index "<< index << " is out of range" << std::endl;
    std::exit(EXIT_FAILURE);

}