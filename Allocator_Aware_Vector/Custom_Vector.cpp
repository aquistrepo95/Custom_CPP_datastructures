#include <iostream>
#include <memory>
#include <initializer_list>
#include "Custom_Vector.h"

// constructor
template < class T, class Allocator >
custom_vector<T, Allocator> :: custom_vector(const Allocator& alloc) {
    this->alloc = alloc;
    ptr   = nullptr;
    size  = 0;
    current_capacity = 0;
} 

// inititializer list constructor
template < class T, class Allocator >
custom_vector<T, Allocator> :: custom_vector(std::initializer_list<T> init, const Allocator& alloc) {
    
    this->alloc = alloc;
    size  = 0;
    current_capacity = init.size();
    ptr = traits::allocate(this->alloc, this->current_capacity);

    for (const auto& item : init) {
        traits::construct(this->alloc, ptr + size, item);
        ++size;
    }

}

// destructor
template < class T, class Allocator >
custom_vector<T, Allocator> :: ~custom_vector() {

    clear();
    traits::deallocate(alloc, ptr, current_capacity);

}

// copy constructor
template < class T, class Allocator >
constexpr custom_vector<T, Allocator> :: custom_vector(const custom_vector& obj, const Allocator& alloc) {
    
    if(obj.isEmpty()) {
        return;
    }

    this->alloc = alloc;
    this->current_capacity = obj.current_capacity;
    this->size = 0;
    this->ptr = traits::allocate(this->alloc, this->current_capacity);

    for(size_type x = 0; x < obj.size; ++x) {
        traits::construct(this->alloc, this->ptr + this->size, *(obj.ptr + x));
        ++this->size;
    }

}

// copy assignment operator
template < class T, class Allocator >
constexpr custom_vector<T, Allocator>& custom_vector<T, Allocator> :: operator=(const custom_vector& obj) {
    
    if(this == &obj) {
        return *this;
    }

    clear();

    if(this->current_capacity < obj.current_capacity) {
        traits::deallocate(this->alloc, this->ptr, this->current_capacity);
        this->current_capacity = obj.current_capacity;
        this->ptr = traits::allocate(this->alloc, this->current_capacity); 
    }

    for(size_type x = 0; x < obj.size; ++x) {
        traits::construct(this->alloc, this->ptr + x, *(obj.ptr + x));
        ++this->size;
    }

    return *this;

}

// move constructor
template < class T, class Allocator >
constexpr custom_vector<T, Allocator> :: custom_vector(custom_vector&& obj) noexcept {
    
    if(obj.isEmpty()) {
        return;
    }

    this->alloc = std::move(obj.alloc);
    this->ptr = obj.ptr;
    this->size  = obj.size;
    this->current_capacity = obj.current_capacity;

    obj.ptr  = nullptr;
    obj.size = 0;
    obj.current_capacity = 0;
}

// move assigmnet operator
template < class T, class Allocator >
custom_vector<T, Allocator>& custom_vector<T, Allocator> :: operator=(custom_vector&& obj) noexcept { 
   
    if(this == &obj) {
        return *this;
    }

    clear();
    traits::deallocate(this->alloc, this->ptr, this->current_capacity);
   
    this->alloc = std::move(obj.alloc);
    this->ptr = obj.ptr;
    this->size  = obj.size;
    this->current_capacity = obj.current_capacity;

    obj.ptr  = nullptr;
    obj.size = 0;
    obj.current_capacity = 0;

    return *this;

}

// reserve_block function to allocate memory
template < class T, class Allocator >
void custom_vector<T, Allocator> :: reserve_block(size_t new_capacity) {
    if(current_capacity >= new_capacity) {
        return;
    }

    // temp pointer to hold newly allocated memory location
    pointer _ptr = traits::allocate(alloc, new_capacity);

    // copy and free elements in the old memory location(ptr) to the new(_ptr)
    for(size_type x = 0; x < size; ++x) {
        traits::construct(alloc, _ptr + x, std::move(*(ptr + x)));
        traits::destroy(alloc, ptr + x);
    }

    // free the old memory block
    if(ptr != nullptr) {
        traits::deallocate(alloc, ptr, current_capacity);
    }

    // assign newly created variable to "this" variables
    ptr = _ptr;
    current_capacity = new_capacity;
}

// push_back function to add new element to the current array
template < class T, class Allocator >
void custom_vector<T, Allocator> :: push_back(const T& element) {
    // check if the current size of the vector is equal to its current capacity => add new memory if needed
    if(size == current_capacity) {
        reserve_block(current_capacity + 1);
    }

    traits::construct(alloc, ptr + size, element);
    ++size;
}

// pop_back function to remove the last element added to the array
template < class T, class Allocator >
void custom_vector<T, Allocator> :: pop_back() {
    if(isEmpty()) {
        return;
    }

    // decrement size => vector start index is 0
    --size;

    // destroy element without deallocating memory
    traits::destroy(alloc, ptr + size);
}

// check if the array is empty return true: array is empty OR false: otherwise
template < class T, class Allocator >
bool custom_vector<T, Allocator> :: isEmpty() const noexcept {
    if(size == 0) {
        return true;
    }
    else {
        return false;
    }

}

// Get the size of the array
template < class T, class Allocator >
int custom_vector<T, Allocator> :: getSize() const noexcept {
    
    return size;
}

// remove all elements from the current array
template < class T, class Allocator >
void custom_vector<T, Allocator> :: clear() {

    for(size_type x = 0; x < size; x++) {
        traits::destroy(alloc, ptr + x);
    }

    size = 0;
}

// overload the [] operator: return the value at a specific index in the array
template < class T, class Allocator >
T& custom_vector<T, Allocator> :: operator[](const int& index) {

    if(index >= 0 && index < size) {
        return *(ptr + index);
    }

    std::cerr << "index "<< index << " is out of range" << std::endl;
    std::exit(EXIT_FAILURE);
}

// iterator functions
// return type(iterator) from begin() and pass the local pointer of custom_vector to the iterator class i.e the 1st element in the vector
template < class T, class Allocator >
typename custom_vector< T, Allocator >::iterator custom_vector< T, Allocator >:: begin() noexcept {

    return iterator(ptr);
}

// return type(iterator) from end() and pass the local pointer + size of custom_vector to the iterator class i.e the last+1 element in the vector
template < class T, class Allocator >
typename custom_vector< T, Allocator >::iterator custom_vector< T, Allocator >:: end() noexcept {

    return iterator(ptr + size);
}