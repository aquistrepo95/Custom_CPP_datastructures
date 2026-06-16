#include <iostream>
#include <vector>
#include "unique_ptr.cpp"

// make_unique template function prototype
template < typename T, typename... Args > 
unique_ptr<T> make_unique(Args&&... args);


int main() {
 
   int value = 67;

   unique_ptr<int> ptr1 = make_unique<int>(value);
   std::cout << "The unique pointer's value for ptr1 is: " << *ptr1 << std::endl;
   
   //move construtor
   unique_ptr<int> ptr2 = std::move(ptr1);
   std::cout << "The unique pointer's value for ptr2 after move constructor is invoked: " << *ptr2 << std::endl;

   
   //modifying the value with reset
   ptr1.reset(new int(87));
   std::cout << "The unique pointer's value for ptr1 after reset is invoked with a new pointer: " << *ptr1 << std::endl;

   // swaping managed resources
   ptr1.swap(ptr2);
   std::cout << "After swapping ptr1 and ptr2 managed resources ptr1 is now: " << *ptr1 << " and ptr2 is now: " << *ptr2 << std::endl;  

   //move assignment 
   ptr2 = std::move(ptr1); 
   std::cout << "The unique pointer's value for ptr2 after move assignment operator is invoked: " << *ptr2<< std::endl;  

   //modying the value with release
   std::cout << "The ptr2 memory location before it was released is: " << ptr2.release() << std::endl;
   

}

template < typename T , typename... Args >
unique_ptr<T> make_unique(Args&&... args) {

    return unique_ptr<T>(new T (std::forward<Args>(args)...));
}
