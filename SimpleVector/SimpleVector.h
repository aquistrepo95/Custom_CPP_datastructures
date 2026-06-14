#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H


/*
    simple rule of 3 vector class with member functions for push_back, pop_back, isEmpty, getSize, operator overload for[],  
    Copy Semantics for Copy Constructor and Copy assignment operator, a default Constructor and a destructor.
*/

template< class T >
class SimpleVector{
    private:
        T *arr;
        T *temp_arr;
        int size;

    public:
        SimpleVector();
        ~SimpleVector();

        SimpleVector(const SimpleVector& obj);
        SimpleVector<T>& operator=(const SimpleVector& obj);

        void push_back(T element);
        void pop_back();
        bool isEmpty();
        int getSize();

        T& operator[](const int& index);

};

#endif 