#ifndef SIMPLEVECTOR_MOVE
#define SIMPLEVECTOR_MOVE


/*
    vector class with member functions for push_back, pop_back, isEmpty, getSize, operator overload for[],  
    Move Semantics for Move Constructor and Move assignment operator, a default Constructor and a destructor.
*/

template< class T >
class SimpleVector_Move{
    private:
        T *arr;
        T *temp_arr;
        int size;

    public:
        explicit SimpleVector_Move() noexcept;
        ~SimpleVector_Move() noexcept;

        SimpleVector_Move(const SimpleVector_Move& obj) = delete;
        SimpleVector_Move<T>& operator=(const SimpleVector_Move& obj) = delete;

        SimpleVector_Move(SimpleVector_Move&& obj) noexcept;
        SimpleVector_Move<T>& operator=(SimpleVector_Move&& obj) noexcept;

        void push_back(const T& element);
        void pop_back();
        bool isEmpty();
        int  getSize();
        void clear();

        T& operator[](const int& index);

};

#endif 