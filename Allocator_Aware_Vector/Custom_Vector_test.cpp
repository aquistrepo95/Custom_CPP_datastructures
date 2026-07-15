#include <gtest/gtest.h>
#include "Custom_Vector.hpp"

class CustomVectorTest : public ::testing::Test {
    protected:
        custom_vector<int> vec;

        void SetUp() override {
            vec = custom_vector<int>({1, 2, 3, 4, 5});
        }
};

TEST_F(CustomVectorTest, PushBackANDPopback) {
    size_t initial_size = vec.getSize();
    vec.push_back(6);
    EXPECT_EQ(vec.getSize(), initial_size + 1);
    EXPECT_EQ(vec[initial_size], 6);

    vec.pop_back();
    EXPECT_EQ(vec.getSize(), initial_size);

    // Test clear function and isEmpty function
    EXPECT_FALSE(vec.isEmpty());
    vec.clear();
    EXPECT_TRUE(vec.isEmpty());
}

TEST_F(CustomVectorTest, CopyConstructorAndAssignment) {
    custom_vector<int> copy_vec = vec;
    EXPECT_EQ(copy_vec.getSize(), vec.getSize());
    for (size_t i = 0; i < vec.getSize(); ++i) {
        EXPECT_EQ(copy_vec[i], vec[i]);
    }

    custom_vector<int> assigned_vec;
    assigned_vec = vec;
    EXPECT_EQ(assigned_vec.getSize(), vec.getSize());
    for (size_t i = 0; i < vec.getSize(); ++i) {
        EXPECT_EQ(assigned_vec[i], vec[i]);
    }
}

TEST_F(CustomVectorTest, MoveConstructorAndAssignment) {
    custom_vector<int> moved_vec = std::move(vec);
    EXPECT_EQ(moved_vec.getSize(), 5);
    EXPECT_EQ(vec.getSize(), 0); // Original vector should be empty after move
    for (size_t i = 0; i < moved_vec.getSize(); ++i) {
        EXPECT_EQ(moved_vec[i], i + 1);
    }

    custom_vector<int> another_vec;
    another_vec = std::move(moved_vec);
    EXPECT_EQ(another_vec.getSize(), 5);
    EXPECT_EQ(moved_vec.getSize(), 0); // Moved-from vector should be empty
    for (size_t i = 0; i < another_vec.getSize(); ++i) {
        EXPECT_EQ(another_vec[i], i + 1);
    }
}

TEST_F(CustomVectorTest, ReserveBlock) {
    size_t initial_capacity = vec.getSize();
    vec.reserve_block(initial_capacity + 10);
    EXPECT_GE(vec.getSize(), initial_capacity); // Size should remain the same
    for (size_t i = 0; i < initial_capacity; ++i) {
        EXPECT_EQ(vec[i], i + 1);
    }
}

TEST_F(CustomVectorTest, IteratorFunctionality) {
    size_t index = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        EXPECT_EQ(*it, index + 1);
        ++index;
    }
    EXPECT_EQ(index, vec.getSize());
}