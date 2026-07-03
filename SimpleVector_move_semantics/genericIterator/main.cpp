#include <iostream>
#include <vector>
#include "genericIterator.cpp"


int main() {

    std::vector<int> vec = {1,2,3,4,5};

    genericIterator<int> it;

    std::cout<< "The 3rd element in the vector is: " << *it << std::endl;

    return 0;
}