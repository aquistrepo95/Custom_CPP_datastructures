/*
    simple rule of 3 vector class with member functions for push_back, pop_back, isEmpty, getSize, operator overload for[],  
    Copy Semantics for Copy Constructor and Copy assignment operator, a default Constructor and a destructor.
*/
#include <iostream>

template < class T>
class SimpleVector {
    private:
        T *arr;
        int size;
        

    public:  
        //constructor
        SimpleVector() {
            this->size = 0;
            this->arr = new T[this->size];
        }

        //destructor
        ~SimpleVector() {
            delete[] arr;
            this->size = 0;

            std::cout << "The destructor was invoked here" << std::endl;
        }

        //copy semantics
        //copy construtor
        SimpleVector(const SimpleVector& obj) {
            this->size = obj.size;
            this->arr  = new T[this->size];

            for(int x = 0; x < this->size; x++) {
                *(this->arr + x) = *(obj.arr + x);
            }
        }

        //copy assignment
        SimpleVector& operator=(const SimpleVector& obj) {
            if(this == &obj) {
                return *this;
            }
            
            delete[] this->arr;
            this->size = 0;

            this->size = obj.size;
            this->arr  = new T[this->size];

            for(int x = 0; x < this->size; x++) {
                *(this->arr + x) = *(obj.arr + x);
            }

            return *this;
        }

        // push_back method to add an element to the array
        void push_back(T element) {
            *(arr + this->size) = element;
            this->size++;
        } 

        // pop_back method to remove an element from the array
        void pop_back() {
            if(size > 0) {
                size--;
            }

        } 

        // check if arr is empty
        bool isEmpty() {
            if(this->size == 0) {
                return true;
            }

            return false;
        }

        // return the current size of arr
        int getSize() {
            return this->size;
        }

        //Overload the [] operator
        T& operator[](const int& index) {
            if(index >= 0 && index < this->size) {
                return *(arr + index);
            }

            std::cerr << "index "<< index << " is out of range" << std::endl;
            std::exit(EXIT_FAILURE);
        }

};

int main() {

    SimpleVector<int> vec1;

    std::cout << "Testing isEmpty member function" << std::endl;
    if(vec1.isEmpty()) {
        std::cout<< "the vector is empty" << std::endl;
    }

    for(int x = 0; x < 5; x++) {
        vec1.push_back(x);
    }

    for(int x = 0; x < vec1.getSize(); x++) {
        std::cout << "Array elements before copy constructor and pop_back and push_back: " << vec1[x] << std::endl;
    }

    vec1.pop_back();
    vec1.push_back(29);
    //vec1[7] = 89;

    for(int x = 0; x < vec1.getSize(); x++) {
        std::cout << "Array elements before copy constructor and after pop_back and push_back(29): " << vec1[x] << std::endl;
    }

    std::cout << "\n" << std::endl;
    std::cout << "################################### copy constructor to create vec2 #############################" << std::endl;
    SimpleVector<int> vec2 = vec1;

    for(int x = 0; x < vec2.getSize(); x++) {
        std::cout << "Array elements after copy constructor with no edits: " << vec2[x] << std::endl;
    }

    vec2.pop_back();
    vec2.push_back(60);

    for(int x = 0; x < vec2.getSize(); x++) {
        std::cout << "Array elements after copy constructor with after pop_back and push_back(60): " << vec2[x] << std::endl;
    }

    std::cout << "\n" << std::endl;
    std::cout << "################################### copy assignment to vec1 after updates #############################" << std::endl;
    vec1 = vec2;

    for(int x = 0; x < vec1.getSize(); x++) {
        std::cout << "Array elements for vec1 obj after copy assignent: " << vec1[x] << std::endl;
    }


    return 0;
}