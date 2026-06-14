#include <iostream>
#include "SimpleVector.cpp"

int main() {
    // instantiate the first object 
    SimpleVector<int> vec1;

    std::cout << "Testing isEmpty member function" << std::endl;
    if(vec1.isEmpty()) {
        std::cout<< "the vector is empty" << std::endl;
    }
    else {
        std::cout << "The vector is not empty" << std::endl;
    }

    for(int x = 0; x < 5; x++) {
        vec1.push_back(x);
    }

    std::cout << "Testing isEmpty member function" << std::endl;
    if(vec1.isEmpty()) {
        std::cout<< "the vector is empty" << std::endl;
    }
    else {
        std::cout << "The vector is not empty" << std::endl;
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