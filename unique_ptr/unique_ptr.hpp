#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

template < class T >
class unique_ptr {
    private:
        T *pointer;

    public:

       // constructor and destructor
       constexpr unique_ptr() noexcept;
       explicit unique_ptr(T* raw_ptr) noexcept;
       ~unique_ptr();

       // copy semantics disabled
       unique_ptr(const unique_ptr& obj) = delete;
       unique_ptr& operator=(const unique_ptr& obj) = delete;

       // move semantics 
       unique_ptr(unique_ptr&& obj) noexcept;
       unique_ptr<T>& operator=(unique_ptr&& obj) noexcept;

       // member functions
       //observers
       T* get() const noexcept; 

       //modifiers
       T* release() noexcept;
       void reset(T* new_pointer = nullptr) noexcept;
       void swap(unique_ptr& obj) noexcept;

       // operator overloads
       T& operator*() const noexcept;
       T* operator->() const noexcept;  

};


#include "unique_ptr.cpp"

#endif
