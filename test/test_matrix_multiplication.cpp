#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult

TEST(MatrixMultiplicationTest, TestMultiplyMatrices)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}};
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

// Testing the zero element of multiplication.
TEST(MatrixMultiplicationTest, TestZeroMatrixRight)
{
    std::vector<std::vector<int>> A = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    std::vector<std::vector<int>> B = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    ASSERT_EQ(C, expected) << "Zero matrix left test failed!";
}

TEST(MatrixMultiplicationTest, TestZeroMatrixLeft)
{
    std::vector<std::vector<int>> A = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    std::vector<std::vector<int>> B = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    ASSERT_EQ(C, expected) << "Zero matrix right test failed!";
}

TEST(MatrixMultiplicationTest, TestIdentityMatrixLeft)
{
    std::vector<std::vector<int>> A = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    std::vector<std::vector<int>> B = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {1, 0, 0},
        {0, 5, 0},
        {0, 0, 9}};

    ASSERT_EQ(C, expected) << "Identity matrix left test failed!";
}

TEST(MatrixMultiplicationTest, TestIdentityMatrixRight)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<std::vector<int>> B = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {1, 0, 0},
        {0, 5, 0},
        {0, 0, 9}};

    ASSERT_EQ(C, expected) << "Identity matrix right test failed!";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
