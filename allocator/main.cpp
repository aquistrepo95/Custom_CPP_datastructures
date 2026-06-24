#include <iostream>
#include <vector>
#include "allocator.cpp"


int main() {
    std::vector < int, allocator<int>> vec;
    
    vec = {1,2,3,4};

    for(int x = 0; x < vec.size(); x++) {
        std::cout << "vec value is: " << vec[x] << std::endl;
    }


    return 0;
}