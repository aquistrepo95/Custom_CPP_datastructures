#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include "control_block.h"


// forward declare weak_ptr
template < class T >
class weak_ptr;


template < class T >
class shared_ptr {
    private:
        T* shared_pointer;
        control_block* shared_cb;

    public:

        //constructors
        constexpr shared_ptr() noexcept; // compile time
        constexpr shared_ptr(T*);

        
        //constructor overload to enable lock() function in weak pointer class
        shared_ptr(T*, control_block*);

        // friend class(weak_ptr)
        friend class weak_ptr<T>;
        
        //destructor
        ~shared_ptr();

        //copy semantics
        shared_ptr(const shared_ptr&);
        shared_ptr<T>& operator=(const shared_ptr&);

        //move semantics
        shared_ptr(shared_ptr&&) noexcept;
        shared_ptr<T>& operator=(shared_ptr&&) noexcept;

        //member functions
        T* get() const noexcept;
        void reset(T* new_pointer = nullptr) noexcept;
        void swap(shared_ptr&) noexcept;
        int use_count() const noexcept;
        bool unique() const noexcept;

        //operator overloading
        T& operator*() const noexcept;
        T* operator->() const noexcept;

};

#endif