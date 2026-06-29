#ifndef CUSTOM_VECTOR_H
#define CUSTOM_VECTOR_H
#include <memory>
#include <initializer_list>
#include "allocator/allocator.cpp"

template< class T, class Allocator = allocator<T> >
class custom_vector{  
    public:

        // exposing information to external algorithms
        using value_type = T;
        using allocator_type = Allocator;
        using size_type  = std::size_t;

        // aliases for wrapper for allocator_traits
        using traits  = std::allocator_traits<Allocator>;
        using pointer = typename traits::pointer;
       
        // constructors
        //custom_vector() = default;
        explicit custom_vector(const Allocator& alloc = Allocator());
        custom_vector(std::initializer_list<T>, const Allocator& alloc = Allocator());

        // destructor
        ~custom_vector();
        
        // copy semantics
        constexpr custom_vector(const custom_vector&, const Allocator& alloc = Allocator());
        constexpr custom_vector<T, Allocator>& operator=(const custom_vector&);

        // move semantics
        constexpr custom_vector(custom_vector&&) noexcept;
        custom_vector<T, Allocator>& operator=(custom_vector&&) noexcept;

        // member functions
        void reserve_block(size_t);
        void push_back(const T&);
        void pop_back();
        bool isEmpty() const noexcept;
        int  getSize() const noexcept;
        void clear();

        // operator overload
        T& operator[](const int&);

    private:
        Allocator alloc;
        pointer ptr;
        size_type size;
        size_type current_capacity;

};

#endif //CUSTOM_VECTOR_H