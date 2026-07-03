#include <iostream>
#include <utility>
#include "shared_ptr.cpp"
#include "weak_ptr.cpp"

// make_shared template function prototype
template < typename T, typename... Args > 
shared_ptr<T> make_shared(Args&&... args);


int main() {

    shared_ptr<int> ptr1 = make_shared<int>(67);
    std::cout << "The ptr1 shared pointer is: " << *ptr1 << std::endl;
    std::cout << "ref_count of ptr2 is: " << ptr1.use_count() << std::endl;
    std::cout << "The address for the resource ptr1 is pointing to: " << ptr1.get() << std::endl;
    
    std::cout << "\n";
    shared_ptr<int> ptr2  = ptr1; // copy constructor
    std::cout << "The ptr2 shared pointer is: " << *ptr2 << std::endl;
    std::cout << "ref_count of ptr2 is: " << ptr2.use_count() << std::endl;
    std::cout << "The address for the resource ptr2 is pointing to: " << ptr2.get() << std::endl;
    std::cout << "\n";
    
    std::cout << "\n";
    shared_ptr<int> ptr3 = make_shared<int>(90);
    std::cout << "The ptr3 shared pointer is: " << *ptr3 << std::endl;
    std::cout << "ref_count of ptr3 is: " << ptr3.use_count() << std::endl;
    std::cout << "The address for the resource ptr3 is pointing to: " << ptr3.get() << std::endl;

    std::cout << "\n";
    ptr2 = ptr3;
    std::cout << "The ptr2 shared pointer is: " << *ptr2 << std::endl;
    std::cout << "ref_count of ptr2 is: " << ptr2.use_count() << std::endl;
    std::cout << "ref_count of ptr3 is: " << ptr3.use_count() << std::endl;
    std::cout << "ref_count of ptr1 is: " << ptr1.use_count() << std::endl;
    std::cout << "The address for the resource ptr2 is pointing to: " << ptr2.get() << std::endl;
    std::cout << "The address for the resource ptr3 is pointing to: " << ptr3.get() << std::endl;
    std::cout << "The address for the resource ptr1 is pointing to: " << ptr1.get() << std::endl;
    
    std::cout << "\n";
    shared_ptr<int> ptr4 = std::move(ptr2);
    std::cout << "The ptr4 shared pointer is: " << *ptr4 << std::endl;
    std::cout << "The ptr3 shared pointer is: " << *ptr3 << std::endl;
    std::cout << "The ptr1 shared pointer is: " << *ptr1 << std::endl;
    std::cout << "ref_count of ptr4 is: " << ptr4.use_count() << std::endl;
    std::cout << "ref_count of ptr3 is: " << ptr3.use_count() << std::endl;
    std::cout << "ref_count of ptr1 is: " << ptr1.use_count() << std::endl;
    std::cout << "The address for the resource ptr4 is pointing to:  " << ptr4.get() << std::endl;
    std::cout << "The address for the resource ptr3 is pointing to:  " << ptr3.get() << std::endl;
    std::cout << "The address for the resource ptr1 is pointing to:  " << ptr1.get() << std::endl;
    
    std::cout << "\n";
    ptr3 = std::move(ptr1);
    std::cout << "The ptr3 shared pointer after move assignment with ptr1 is: " << *ptr3 << std::endl;
    std::cout << "The ptr4 shared pointer is: " << *ptr4 << std::endl;

    std::cout << "\n";
    ptr3.swap(ptr4);
    std::cout << "The ptr3 shared pointer after swap with ptr4 is: " << *ptr3 << std::endl;
    std::cout << "The ptr4 shared pointer after swap with ptr3 is: " << *ptr4 << std::endl;

    std::cout << "\n";
    ptr3.reset(new int(66));
    std::cout << "The ptr3 shared pointer after reset with new value is: " << *ptr3 << std::endl;
    std::cout << "ref_count of ptr3 is: " << ptr3.use_count() << std::endl;

    std::cout << "\n";
    // testing unique member function
    if(ptr3.unique()) {
        std::cout << "The managed object is being managed by one shared pointer" << std::endl;
    }
    else {
        std::cout << "The managed object is being managed by more than one shared pointer" << std::endl;
    }

    {
    // shared pointer resource created     
    shared_ptr<int> ptr5 = make_shared<int>(75);
    shared_ptr<int> ptr6 = make_shared<int>(43);
    std::cout << "\n";
    weak_ptr<int> wptr1 = ptr5;
    weak_ptr<int> wptr2 = ptr5;
    std::cout << "The ptr5 shared pointer is: " << *ptr5 << std::endl;
    std::cout << "ref_count of ptr5 is: " << ptr5.use_count() << std::endl;
    std::cout << "ref_count of wptr2 is:  " << wptr2.use_count() << std::endl;

    std::cout << "\n";
    wptr2 = ptr6;
    std::cout << "The ptr6 shared pointer is: " << *ptr6 << std::endl;
    std::cout << "ref_count of ptr6 is: "   << ptr6.use_count() << std::endl;
    std::cout << "ref_count of wptr2 is:  " << wptr2.use_count() << std::endl;
    
    std::cout << "\n";
    wptr2.swap(wptr1);
    std::cout << "ref_count of wptr2 is:  " << wptr2.use_count() << std::endl;
    std::cout << "ref_count of wptr1 is:  " << wptr1.use_count() << std::endl;

    std::cout << "\n";
    shared_ptr<int> ptr7 = make_shared<int>(80);
    weak_ptr<int> wptr3 = ptr7;
    std::cout << "The ptr7 shared pointer is: " << *ptr7 << std::endl;
    std::cout << "ref_count of ptr7 is: "   << ptr7.use_count() << std::endl;
    std::cout << "ref_count of wptr3 is:  " << wptr3.use_count() << std::endl;

    std::cout << "\n";
    ptr7.reset();
    if(wptr3.expired()) {
        std::cout << "The shared pointer has been release for ptr7" << std::endl;
    }
    else {
        std::cout << "The shared pointer has not been release for ptr7" << std::endl;
    }

    std::cout << "\n";
    shared_ptr<int> ptr8 = make_shared<int>(73);
    weak_ptr<int> wptr4 = ptr8;
    std::cout << "The ptr8 shared pointer is: " << *ptr8 << std::endl;
    std::cout << "ref_count of ptr8 is: "   << ptr8.use_count() << std::endl;
    std::cout << "ref_count of wptr4 is:  " << wptr4.use_count() << std::endl;
    // lock() function
    wptr4.lock();
    std::cout << "The ptr8 shared pointer is: " << *ptr8 << std::endl;
    std::cout << "ref_count of ptr8 is: "   << ptr8.use_count() << std::endl;
    std::cout << "ref_count of wptr4 is:  " << wptr4.use_count() << std::endl;
    std::cout << "\n";

    }
    
    return 0;
}


// make_shared template function definition
template < typename T, typename... Args > 
shared_ptr<T> make_shared(Args&&... args){

    return shared_ptr<T>(new T (std::forward<Args>(args)...));
}