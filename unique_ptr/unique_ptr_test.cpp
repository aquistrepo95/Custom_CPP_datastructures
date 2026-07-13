#include <gtest/gtest.h>
#include <memory>
#include "unique_ptr.hpp"

class UniqueptrTest : public testing::Test {
    protected:
    // custom make_unique function
    template < typename T , typename... Args >
        unique_ptr<T> make_unique(Args&&... args) {
        return unique_ptr<T>(new T (std::forward<Args>(args)...));
    }
    
    
    void SetUp() override {
        ptr_1 = make_unique<int>(42);
    }

    unique_ptr<int> ptr_1;

};

// initialization test
TEST_F(UniqueptrTest, UniquePtrInitializationTest){
    ASSERT_NE(ptr_1.get(), nullptr);
}

// Move Semantics Tests
TEST_F (UniqueptrTest, UniquePtrMoveSemanticsTest){
    unique_ptr<int> ptr_2 = std::move(ptr_1);
    ASSERT_EQ(ptr_1.get(), nullptr);
    ASSERT_NE(ptr_2.get(), nullptr);

    ptr_1 = std::move(ptr_2);
    ASSERT_EQ(ptr_2.get(), nullptr);
    ASSERT_NE(ptr_1.get(), nullptr);
}

// Reset Test
TEST_F (UniqueptrTest, UniquePtrResetTest){
    ptr_1.reset(new int(100));
    ASSERT_EQ(*ptr_1, 100);

    std::cout << "ptr_1 value after reset: " << *ptr_1 << std::endl;
}

// Swap Test
TEST_F (UniqueptrTest, UniquePtrSwapTest){
    unique_ptr<int> ptr_2 = make_unique<int>(200);
    ptr_1.swap(ptr_2);
    ASSERT_EQ(*ptr_1, 200);
    ASSERT_EQ(*ptr_2, 42);

    std::cout << "ptr_1 value after swap: " << *ptr_1 << std::endl;
    std::cout << "ptr_2 value after swap: " << *ptr_2 << std::endl;
}

// Release Test
TEST_F (UniqueptrTest, UniquePtrReleaseTest){
    int* raw_ptr = ptr_1.release();
    ASSERT_EQ(ptr_1.get(), nullptr);
    ASSERT_NE(raw_ptr, nullptr);
    ASSERT_EQ(*raw_ptr, 42);

    std::cout << "ptr_1 value after release: " << (ptr_1.get() == nullptr ? "nullptr" : std::to_string(*ptr_1)) << std::endl;
    std::cout << "raw_ptr value after release: " << *raw_ptr << std::endl;

    delete raw_ptr;
}