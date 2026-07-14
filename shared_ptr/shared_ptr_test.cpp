#include <gtest/gtest.h>
#include "shared_ptr.hpp"

class sharedPtrTest : public ::testing::Test {
    protected:

    // custom make_shared function
    template < typename T, typename... Args >
    shared_ptr<T> make_shared(Args&&... args) {
    return shared_ptr<T>(new T (std::forward<Args>(args)...));
    }

    void SetUp() override {
        ptr_1 = make_shared<int>(42);
    }

    shared_ptr<int> ptr_1;

};

TEST_F(sharedPtrTest, TestConstructors) {
    EXPECT_NE(ptr_1.get(), nullptr);
    EXPECT_EQ(ptr_1.use_count(), 1);
}

TEST_F(sharedPtrTest, TestCopySemantics) {
    shared_ptr<int> ptr_2 = ptr_1;
    EXPECT_EQ(ptr_1.use_count(), 2);
    EXPECT_EQ(ptr_2.use_count(), 2);

    shared_ptr<int> ptr_3;
    ptr_3 = ptr_1;
    EXPECT_EQ(ptr_1.use_count(), ptr_3.use_count());
}

TEST_F(sharedPtrTest, TestMoveSemantics) {
    shared_ptr<int> ptr_2 = std::move(ptr_1);
    EXPECT_EQ(ptr_2.use_count(), 1);
    EXPECT_EQ(ptr_1.get(), nullptr);

    shared_ptr<int> ptr_3;
    ptr_3 = std::move(ptr_2);
    EXPECT_EQ(ptr_3.use_count(), 1);
    EXPECT_EQ(ptr_2.get(), nullptr);
}

TEST_F(sharedPtrTest, TestResetAndSwap) {
    shared_ptr<int> ptr_2 = make_shared<int>(100);
    ptr_1.swap(ptr_2);
    EXPECT_EQ(*ptr_1, 100);
    EXPECT_EQ(*ptr_2, 42);

    ptr_1.reset();
    EXPECT_EQ(ptr_1.get(), nullptr);
    EXPECT_EQ(ptr_1.use_count(), 0);
}