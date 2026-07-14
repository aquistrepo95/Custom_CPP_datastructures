#include <gtest/gtest.h>
#include "allocator.hpp"

TEST(AllocatorTest, AllocateDeallocate) {
    allocator<int> alloc;

    // Test allocation of 5 integers
    int* ptr = alloc.allocate(5);
    ASSERT_NE(ptr, nullptr); 

    // Test deallocation
    alloc.deallocate(ptr, 5);

}