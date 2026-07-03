#include <iostream>
#include "genericIterator.h"


// default constructor
template < class T > 
genericIterator<T> :: genericIterator() {
    ptr_ = nullptr;
}

// parameterized constructor
template < class T >
genericIterator<T> :: genericIterator(pointer ptr) {
    ptr_ = ptr;
}

// overload the dereference operator
template < class T >
typename genericIterator<T>:: reference genericIterator<T> :: operator*() const{
    return *(ptr_);
}

// overload the reference operator
template < class T >
typename genericIterator<T>:: pointer genericIterator<T> :: operator->() {
    return ptr_;
}

// overload the prefix increment operator
template < class T >
genericIterator<T>& genericIterator<T> :: operator++() {
    ++ptr_;
    return *this;
}

// overload the prefix decrement operator
template < class T >
genericIterator<T>& genericIterator<T> :: operator--() {
    --ptr_;
    return *this;
}

// overload the postfix operator
template < class T >
genericIterator<T> genericIterator<T> :: operator++(int) {
    genericIterator temp = *this;
    ptr_++;
    return temp;
}

// overload the postfix decrement operator
template < class T >
genericIterator<T> genericIterator<T> :: operator--(int) {
    genericIterator temp = *this;
    ptr_--;
    return temp;
}

// friend functions for comparison
template < class U >
bool operator==(const genericIterator<U>& obj , const genericIterator<U>& obj1) {
    return obj.ptr_ == obj1.ptr_; 
} 

template < class U >
bool operator!=(const genericIterator<U>& obj , const genericIterator<U>& obj1) {
    return obj.ptr_ != obj1.ptr_;
} 

template < class U >
bool operator>(const genericIterator<U>& obj , const genericIterator<U>& obj1) {
    return obj.ptr_ > obj1.ptr_;
} 

template < class U >
bool operator<(const genericIterator<U>& obj , const genericIterator<U>& obj1) {
    return obj.ptr_ < obj1.ptr_;
} 