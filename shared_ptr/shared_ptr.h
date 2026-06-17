#ifndef SHARED_PTR_H
#define SHARED_PTR_H

template < class T >
class shared_ptr{
    private:
        T* pointer;
        T* ref_count;

    public:

        //constructors
        constexpr shared_ptr() noexcept; // compile time
        explicit shared_ptr(T* raw_pointer);

        //destructor
        ~shared_ptr() noexcept;

        //copy semantics
        shared_ptr(const shared_ptr& obj);
        shared_ptr<T>& operator=(const shared_ptr& obj);

        //move semantics
        shared_ptr(shared_ptr&& obj) noexcept;
        shared_ptr<T>& operator=(shared_ptr&& obj) noexcept;

        //member functions
        T* get() const noexcept;
        void reset(T* new_pointer = nullptr) noexcept;
        void swap(shared_ptr& obj) noexcept;
        int use_count() const noexcept;
        bool unique() const noexcept;

        //operator overloading
        T& operator*() const noexcept;
        T* operator->() const noexcept;

};

#endif