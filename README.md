# SE4HPCproject
The purpose of this first part of the project is to test a buggy implementation of the matrix multiplication software provided in the directory [lib](https://github.com/marcolacagnina/Lacagnina-Lentini-part1/tree/main/lib).

Since the matrix multiplication function was provided as compiled object code, we tested it in a black box manner. To identify errors, we started by testing some fundamental mathematical properties of matrix multiplication, adapting each subsequent test based on the error outputs from the previous tests.

Summary of the tests:
Summary of the errors:

1. Result matrix contains a 0. 
2. Matrix A contains the number 7.
3. Matrix A is a square matrix
4. The number of rows in A is uqual to the number of columns in B.
5. The number of columns in A is odd.
6. Every row in B contains at least one 0.
7. The first element in matrix A is equal to the first element in matrix B.
8. Element-wise multiplication of ones detected.
9. The matrix A contains a negative number.
10. The matrix B contains a negative number.
11. The matrix C contains a number bigger than 100.
12. The matrix C has an even number of rows.
13. A row in matrix A is filled entirely with 5s. (Error 15)
