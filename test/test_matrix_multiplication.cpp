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

/**
 * @brief Test for multiplying a matrix with a zero matrix on the left.
 *        The result should be a zero matrix, since any matrix multiplied
 *        by a zero matrix is a zero matrix.
 *
 *
 * From the test execution, the test failed for the following reasons:
 * 1. Result matrix contains a 0.
 * 2. Matrix A contains the number 7.
 * 3. Matrix A is a square matrix.
 * 4. The number of rows in A is uqual to the number of columns in B.
 * 5. The number of columns in A is odd.
 * 6. Every row in B contains at least one 0.
 */
TEST(MatrixMultiplicationTest, TestZeroMatrixRight)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<std::vector<int>> B = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    ASSERT_EQ(C, expected) << "Zero matrix left test failed!";
}

/**
 * @brief Test for multiplying a matrix with an identity matrix on the right.
 *        The result should be the same matrix, since any matrix multiplied
 *        by an identity matrix is the same matrix.
 *
 * From the test execution, the test failed for the following reasons:
 * 6. Every row in B contains at least one 0.
 * 7. The first element in matrix A is equal to the first element in matrix B.
 * 8. Element-wise multiplication of ones detected.
 */
TEST(MatrixMultiplicationTest, TestIdentityMatrixRight)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
    };
    std::vector<std::vector<int>> B = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};
    std::vector<std::vector<int>> C(3, std::vector<int>(4, 0));

    multiplyMatrices(A, B, C, 3, 4, 4);

    std::vector<std::vector<int>> expected = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };

    ASSERT_EQ(C, expected) << "Identity matrix left test failed!";
}

/**
 * @brief Test for multiplying two negative matrices.
 *        The result should be a matrix with positive numbers.
 *
 * From the test execution, the test failed for the following reasons:
 * 9. The matrix A contains a negative number.
 * 10. The matrix B contains a negative number.
 * 11. The matrix C contains a number bigger than 100.
 * 12. The matrix C has an even number of rows.
 */
TEST(MatrixMultiplicationTest, TestNegativeMatrices)
{
    std::vector<std::vector<int>> A = {
        {-1, -2, -3, -4},
        {-4, -5, -6, -7}};
    std::vector<std::vector<int>> B = {
        {-7, -8, -9, -10},
        {-11, -12, -13, -14},
        {-15, -16, -17, -18},
        {-19, -20, -21, -22}};
    std::vector<std::vector<int>> C(2, std::vector<int>(4, 0));

    multiplyMatrices(A, B, C, 2, 4, 4);

    std::vector<std::vector<int>> expected = {
        {110, 120, 130, 140},
        {248, 272, 296, 320}};

    ASSERT_EQ(C, expected) << "Negative matrix multiplication test failed!";
}

/**
 * @brief Test for computing the squared norm of a 2x1 matrix (bi-dimensional vector).
 *        The result should be a 1x1 matrix with the squared norm of the input matrix.
 *
 * From the test execution, the test failed for the following reasons:
 * 4. The number of rows in A is equal to the number of columns in B
 * 7. The first element of matrix A is equal to the first element of matrix B
 * 13. A row in matrix A is filled entirely with 5s.
 */
TEST(MatrixMultiplicationTest, TestSquaredNormComputation)
{
    std::vector<std::vector<int>> A = {
        {5, 5}};
    std::vector<std::vector<int>> B = {
        {5},
        {5}};
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 2, 1);

    std::vector<std::vector<int>> expected = {
        {50}};

    ASSERT_EQ(C, expected) << "Square norm computation test failed!";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
