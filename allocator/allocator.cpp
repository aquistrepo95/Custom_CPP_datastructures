#include <iostream>
#include <new>
#include "allocator.h"

// allocate function to allocate unitialized memory
template < class T >
constexpr T* allocator<T> :: allocate(std::size_t size) {
    // ensure size requested is not zero(0), return nullptr if size requested is 0
    if(size == 0) {
        return nullptr;
    }


    // throw exception if the size of memory reuested is too large
    if(size > std::size_t(-1) / sizeof(T)) {
        throw std::bad_array_new_length();
    }

    // allocate memory through global new operator
    void* memory_ptr = ::operator new((size * sizeof(T)));

    std::cout << "allocating: " << (size * sizeof(T)) << " bytes for: " << size << " elements of type " << typeid(T).name() << std::endl; 

    // convert memory to the data type that was requested and return it to the calling program
    return static_cast<T*>(memory_ptr);
}

// deallocate function to deallocate memory
template < class T >
constexpr void allocator<T> :: deallocate(T* memory_ptr, std::size_t size) {

    std::cout << "deallocating: " << (size * sizeof(T)) << " bytes for: " << size << " elements of type " << typeid(T).name() << std::endl;

    // deallocate memory that was passed
    ::operator delete(memory_ptr);
}

template < typename T, typename U >
constexpr bool operator==(const allocator<T>&, const allocator<U>& ) noexcept {

    return true;
}

template < typename T, typename U >
constexpr bool operator!=(const allocator<T>& , const allocator<U>& ) noexcept {

    return false;
}
