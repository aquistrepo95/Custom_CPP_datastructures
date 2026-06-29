#ifndef GENERICITERATOR_H
#define GENERICITERATOR_H
#include <iterator>
#include <cstddef>

template < class T >
class genericIterator {
    public:
        // mandatory names for external stl libraries and utilities
        // iterator support for external operations like std::sort
        using iterator_category = std::random_access_iterator_tag;
        // expose the data type
        using value_type = T;
        // signed interger type to calculate distance between iterators
        using difference_type = std::ptrdiff_t; // cstddef
        // expose pointer variable
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

        // overload the prefix increments and decrements (++it & --it)
        genericIterator& operator++();
        genericIterator& operator--();

        // overload postfix increments and decrements (it++ & it--)
        genericIterator operator++(int);
        genericIterator operator--(int);

        // overload [] for subscript
        //reference operator[](difference_type) const;

        // overload comparison operators
        template < class  U >
        friend bool operator==(const genericIterator<U>& , const genericIterator<U>& );

        template < class  U >
        friend bool operator!=(const genericIterator<U>& , const genericIterator<U>& );

        template < class  U >
        friend bool operator>(const genericIterator<U>& , const genericIterator<U>& );

        template < class  U >
        friend bool operator<(const genericIterator<U>& , const genericIterator<U>& );


    private:
       pointer ptr;     

};


#endif //GENERICITERATOR_H
