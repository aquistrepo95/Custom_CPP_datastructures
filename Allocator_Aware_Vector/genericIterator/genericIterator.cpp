#include <iostream>
#include "genericIterator.h"


// default constructor
template < class T > 
genericIterator<T> :: genericIterator() {
    this->ptr = nullptr;
}

// parameterized constructor
template < class T >
genericIterator<T> :: genericIterator(pointer ptr) {
    this->ptr = ptr;
}

// overload the dereference operator
template < class T >
typename genericIterator<T>:: reference genericIterator<T> :: operator*() const{
    return *(this->ptr);
}

// overload the reference operator
template < class T >
typename genericIterator<T>:: pointer genericIterator<T> :: operator->() {
    return this->ptr;
}

// overload the prefix increment operator
template < class T >
genericIterator<T>& genericIterator<T> :: operator++() {
    ++this->ptr;
    return *this;
}

// overload the prefix decrement operator
template < class T >
genericIterator<T>& genericIterator<T> :: operator--() {
    --this->ptr;
    return *this;
}

// overload the postfix operator
template < class T >
genericIterator<T> genericIterator<T> :: operator++(int) {
    genericIterator temp = *this;
    this->ptr++;
    return temp;
}

// overload the postfix decrement operator
template < class T >
genericIterator<T> genericIterator<T> :: operator--(int) {
    genericIterator temp = *this;
    this->ptr--;
    return temp;
}

/*
// overload the the subscript operator
template < class T >
refer genericIterator
*/

// friend functions for comparison
template < class U >
bool operator==(const genericIterator<U>& obj , const genericIterator<U>& obj1) {
    return obj.ptr == obj1.ptr; 
} 

template < class U >
bool operator!=(const genericIterator<U>& obj , const genericIterator<U>& obj1) {
    return obj.ptr != obj1.ptr;
} 

template < class U >
bool operator>(const genericIterator<U>& obj , const genericIterator<U>& obj1) {
    return obj.ptr > obj1.ptr;
} 

template < class U >
bool operator<(const genericIterator<U>& obj , const genericIterator<U>& obj1) {
    return obj.ptr < obj1.ptr;
} 