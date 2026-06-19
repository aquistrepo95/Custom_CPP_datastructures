#include <iostream>
#include "shared_ptr.cpp"

// make_shared template function prototype
template < typename T, typename... Args > 
shared_ptr<T> make_shared(Args&&... args);


int main() {
    shared_ptr<int> ptr1 = make_shared<int>(90);

    std::cout << "ptr1's value is: " << *ptr1 << std::endl; 
    std::cout << "ptr1's ref count is: " << ptr1.use_count() << std::endl;

    // copy constructor
    shared_ptr<int> ptr2 = ptr1;
    std::cout << "ptr2's value after copy constructor of ptr1 is: " << *ptr2 << std::endl; 
    std::cout << "ptr2's ref count after copy constructor of ptr1 is: " << ptr2.use_count() << std::endl;

    // reset function on ptr1
    ptr1.reset(new int (65));
    std::cout << "ptr1's value after reset is: " << *ptr1 << std::endl; 
    std::cout << "ptr1's ref count after reset is: " << ptr1.use_count() << std::endl;

    // copy assignment operator
    ptr2 = ptr1;
    std::cout << "ptr2's value after copy assignment of ptr1 is: " << *ptr2 << std::endl; 
    std::cout << "ptr2's ref count after copy assignment of ptr1 is: " << ptr2.use_count() << std::endl;

    // move constructor
    shared_ptr<int> ptr3 = std::move(ptr2);
    std::cout << "ptr3's value after move constructor of ptr2 is: " << *ptr3 << std::endl; 
    std::cout << "ptr3's ref count after move constructor of ptr2 is: " << ptr3.use_count() << std::endl;

    // reset function on ptr3
    ptr3.reset(new int (45));
    std::cout << "ptr3's value after reset is: " << *ptr3 << std::endl; 
    std::cout << "ptr3's ref count after reset is: " << ptr3.use_count() << std::endl;

    // move assignment operator
    ptr2 = std::move(ptr3);
    std::cout << "ptr2's value after move assignment of ptr2 is: " << *ptr2 << std::endl; 
    std::cout << "ptr2's ref count after move assignment of ptr2 is: " << ptr2.use_count() << std::endl;

    shared_ptr<int>ptr4 = ptr1;
    //std::cout << ptr4.use_count() << std::endl;

    // swap function: swapping ptr1 with ptr2
    ptr2.swap(ptr4);
    std::cout << "ptr2's value after swapping with ptr1 is: " << *ptr2 << std::endl; 
    std::cout << "ptr2's ref count after swapping with ptr1 is: " << ptr2.use_count() << std::endl;
    std::cout << "ptr1's value after swapping with ptr2 is: " << *ptr4 << std::endl; 
    std::cout << "ptr1's ref count after swapping with ptr2 is: " << ptr4.use_count() << std::endl;

    // get function
    std::cout << "stored pointer for ptr2 is: " << ptr2.get() << std::endl;

    // unique function
    shared_ptr<int> ptr5 = make_shared<int>(12);
    ptr5 = ptr2;
    /*
    if(ptr2.unique()) {
        std::cout << "This resource is managed by one pointer" << std::endl; 
    }
    */

    if(ptr4.unique()) {
        std::cout << "This resource is managed by one pointer" << std::endl; 
    }
    else{
        std::cout << "This resource is managed by more than one pointer" << std::endl;
    }

    

    return 0;
}

template < typename T, typename... Args > 
shared_ptr<T> make_shared(Args&&... args) {

return shared_ptr<T>(new T (std::forward<Args>(args)...));
}