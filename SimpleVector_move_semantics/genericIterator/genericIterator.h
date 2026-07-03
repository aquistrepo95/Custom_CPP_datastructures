#ifndef GENERICITERATOR_H
#define GENERICITERATOR_H
#include <iterator>
#include <cstddef>

template < class T >
class genericIterator {
    public:
        // mandatory names for external stl libraries and utilities
        // iterator support for linear operations
        using iterator_category = std::forward_iterator_tag; // iterator api
        // expose the data type
        using value_type = T;
        // set the data type for find the distance between elements in the container
        using difference_type = std::ptrdiff_t; // cstddef
        // expose pointer variable type
        using pointer = T*;
        // expose reference for data
        using reference = T&;


        // constructors
        // default constructor
        genericIterator();
        // parameterized constructor
        genericIterator(pointer);


        // operator overloading
        // overload the dereference operator
        reference operator*() const;

        // overload the  operator
        pointer operator->();

        // overload the prefix increment(++it)
        genericIterator& operator++();

        // overload postfix increment(it++)
        genericIterator operator++(int);

        // overload comparison operators
        template < class  U >
        friend bool operator==(const genericIterator<U>& , const genericIterator<U>& );

        template < class  U >
        friend bool operator!=(const genericIterator<U>& , const genericIterator<U>& );

    private:
       pointer ptr;     

};


#endif //GENERICITERATOR_H
