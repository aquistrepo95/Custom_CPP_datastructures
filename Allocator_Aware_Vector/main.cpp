#include <iostream>
#include "Custom_Vector.cpp"


int main() {
    
    custom_vector<int> vect2;

    vect2.push_back(89);
    vect2.push_back(90);

    for(int x = 0; x < vect2.getSize(); x++) {
        std::cout << "Elemenet index: " << x << " is: "<<vect2[x] << std::endl;
    }

    std::cout << "This size of vect2 before pop_back() is: " << vect2.getSize() << std::endl;
    vect2.pop_back();
    std::cout << "This size of vect2 after pop_back() is: " << vect2.getSize() << std::endl;
    vect2.clear();
    std::cout << "This size of vect2 after clear() is: " << vect2.getSize() << std::endl;
    std::cout << "\n";

    {

    custom_vector<int> vect1 = {1,2,3,4,5};
    
    for(int x = 0; x < vect1.getSize(); x++) {
        std::cout << "Elemenet in vect1 index " << x << " is: "<<vect1[x] << std::endl;
    }
    std::cout << "\n";

    // copy constructor
    custom_vector<int> vect3 = vect1;
    
    std::cout << "After copy constructor: custom_vector<int> vect3 = vect1" << std::endl;
    for(int x = 0; x < vect3.getSize(); x++) {
        std::cout << "Elemenet in vect3 index " << x << " is: "<<vect3[x] << std::endl;
    }
    std::cout << "\n";

    // copy assignment operator
    custom_vector<float> vect4 = {8.32, 9.0, 9.99, 1, 2345};
    custom_vector<float> vect5 = {9, 9, 9, 8, 7};

    vect5 = vect4;


    std::cout << "After copy assignment operator: vect5 = vect4" << std::endl;
    for(int x = 0; x < vect5.getSize(); x++) {
        std::cout << "Elemenet in vect5 index " << x << " is: "<<vect5[x] << std::endl;
    }
    std::cout << "\n";
    
    }

    {

    std::cout << "\n";    
    // move constructor
    custom_vector<int> vect6 = {1,2,3,4,5,6};
    custom_vector<int> vect7 = std::move(vect6);

    std::cout << "After move constructor: custom_vector<int> vect7 = std::move(vect6)" << std::endl;
    for(int x = 0; x < vect7.getSize(); x++) {
        std::cout << "Elemenet in vect7 index " << x << " is: "<<vect7[x] << std::endl;
    }
    std::cout << "\n"; 

    // move assignment operator
    custom_vector<int> vect8 = {7,8,9,10};
    vect8 = std::move(vect7);

    std::cout << "After move constructor: vect8 = std::move(vect7)" << std::endl;
    for(int x = 0; x < vect8.getSize(); x++) {
        std::cout << "Elemenet in vect8 index " << x << " is: "<<vect8[x] << std::endl;
    }
    std::cout << "\n";

    }
    

    {

    std::cout << "Iterator" << std::endl;

    custom_vector<int>vect9 = {1,2,3,4,4,5,6,6,7,8,9,10};
    for(auto& m : vect9) {
        std::cout << "Elemenet in vect9 is: "<< m << std::endl;
    }

    auto it = vect9.begin();

    std::cout << *it + 3 << std::endl;

    }

    return 0;
}    