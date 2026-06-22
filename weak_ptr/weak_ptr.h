#ifndef WEAK_PTR_H
#define WEAK_PTR_H
#include "control_block.h"

//forward declaration for shared_ptr
template < class T >
class shared_ptr;


template < class T >
class weak_ptr {
    private:
        T* weak_pointer;
        control_block* weak_cb; 

    public:

        //constructors
        constexpr weak_ptr() noexcept;

        //constructor for shared_ptr object
        weak_ptr(const shared_ptr<T>&);

        //assginment operator for shared_ptr object
        weak_ptr<T>& operator=(const shared_ptr<T>&);

        //destructors
        ~weak_ptr();

        //copy constructor 
        weak_ptr(const weak_ptr&);

        //copy assignment operator
        weak_ptr<T>& operator=(const weak_ptr&);

        //member functions
        void reset() noexcept;
        void swap(weak_ptr&) noexcept;
        int use_count() const noexcept;
        bool expired() const noexcept;
        shared_ptr<T> lock() const noexcept;

};

#endif