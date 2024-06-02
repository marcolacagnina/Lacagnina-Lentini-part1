# SE4HPCproject
The purpose of this first part of the project is to test a buggy implementation of the matrix multiplication software provided in the directory [lib](https://github.com/marcolacagnina/Lacagnina-Lentini-part1/tree/main/lib).

Since the matrix multiplication function was provided as compiled object code, we tested it in a black box manner. To identify errors, we started by testing some fundamental mathematical properties of matrix multiplication, adapting each subsequent test based on the error outputs from the previous tests. 

## Summary of the tests:
We propose a summary of the tests performed on the matrix multiplication software. A wider description of each test and the errors spotted by it can be found in the documentation of [test_matrix_multiplication.cpp](https://github.com/marcolacagnina/Lacagnina-Lentini-part1/blob/main/test/test_matrix_multiplication.cpp). 


We indicated with **A** the left matrix, **B** the right matrix, **C<sub>exp</sub>** the expected resulting matrix and **C<sub>act</sub>** the actual result of the operation.
### 1. TestZeroMatrix
Test for multiplying a matrix with a zero matrix. 
```math
$$
\stackrel{A}{\begin{pmatrix}
1 & 2 & 3 \\
4 & 5 & 6 \\
7 & 8 & 9
\end{pmatrix}}

\times

\stackrel{B}{\begin{pmatrix}
0 & 0 & 0 \\
0 & 0 & 0 \\
0 & 0 & 0
\end{pmatrix}}
=

\stackrel{C_{exp}}{\begin{pmatrix}
0 & 0 & 0 \\
0 & 0 & 0 \\
0 & 0 & 0
\end{pmatrix}}

\quad
\quad

\stackrel{C_{act}}{\begin{pmatrix}
2075 & 7 & 8 \\
6 & 4 & 6 \\
7 & 3 & 10
\end{pmatrix}}

$$
```

### 2. TestIdentityMatrix
Test for multiplying a matrix with an identity matrix.
```math
$$
\stackrel{A}{\begin{pmatrix}
1 & 2 & 3 & 4 \\
1 & 2 & 3 & 4 \\
1 & 2 & 3 & 4 
\end{pmatrix}}

\times

\stackrel{B}{\begin{pmatrix}
1 & 0 & 0 & 0 \\
0 & 1 & 0 & 0 \\
0 & 0 & 1 & 0 \\
0 & 0 & 0 & 1
\end{pmatrix}}
=

\stackrel{C_{exp}}{\begin{pmatrix}
1 & 2 & 3 & 4 \\
1 & 2 & 3 & 4 \\
1 & 2 & 3 & 4
\end{pmatrix}}

\quad
\quad

\stackrel{C_{act}}{\begin{pmatrix}
2011 & 2 & 3 & 4 \\
5 & 2 & 3 & 4 \\
8 & 2 & 3 & 4
\end{pmatrix}}

$$
```


### 3. TestNegativeMatrices
Test for multiplying two negative matrices.
```math
$$
\stackrel{A}{\begin{pmatrix}
-1 & -2 & -3 & -4 \\
-4 & -5 & -6 & -7 
\end{pmatrix}}

\times

\stackrel{B}{\begin{pmatrix}
-7 & -8 & -9 & -10 \\
-11 & -12 & -13 & -14 \\
-15 & -16 & -17 & -18 \\
-19 & -20 & -21 & -22
\end{pmatrix}}
=

\stackrel{C_{exp}}{\begin{pmatrix}
110 & 120 & 130 & 140 \\
248 & 272 & 296 & 320 
\end{pmatrix}}

\quad
\quad

\stackrel{C_{act}}{\begin{pmatrix}
2017 & 221 & 217 & 233 \\
347 & 389 & 395 & 432 
\end{pmatrix}}

$$
```

### 4. TestSquaredNormComputation
Test for computing the squared norm of a 2x1 matrix.
```math
$$
\stackrel{A}{\begin{pmatrix}
5 & 5
\end{pmatrix}}

\times

\stackrel{B}{\begin{pmatrix}
5 \\
5
\end{pmatrix}}
=

\stackrel{C_{exp}}{\begin{pmatrix}
50
 \end{pmatrix}}

\quad
\quad

\stackrel{C_{act}}{\begin{pmatrix}
2053
\end{pmatrix}}

$$
```

### 5. Transpose
Test for verifying the transpose property of the matrix multiplication. A = **B<sup>t</sup>**, B = **A<sup>t</sup>**, C = **(A*B)<sup>t</sup>**.

```math
$$
\stackrel{A}{\begin{pmatrix}
1 & 7 & 3 \\
9 & 2 & 2 \\
4 & 4 & 8
\end{pmatrix}}

\times

\stackrel{B}{\begin{pmatrix}
5 & 4 & 2 \\
1 & 1 & 9 \\
1 & 3 & 4
\end{pmatrix}}
=

\stackrel{C_{exp}}{\begin{pmatrix}
15 & 20 & 77 \\
49 & 44 & 44 \\
32 & 44 & 76
\end{pmatrix}}

\quad
\quad

\stackrel{C_{act}}{\begin{pmatrix}
2019 & 30 & 84 \\
49 & 49 & 44 \\
32 & 54 & 76
\end{pmatrix}}

$$
```


### 6. MatrixVector
Test for multiplying a matrix and a vector.
```math
$$
\stackrel{A}{\begin{pmatrix}
16 & 23 \\
3 & 9 \\
1 & 1
\end{pmatrix}}

\times

\stackrel{B}{\begin{pmatrix}
5 \\
9
\end{pmatrix}}
=

\stackrel{C_{exp}}{\begin{pmatrix}
287 \\
96 \\
14
\end{pmatrix}}

\quad
\quad

\stackrel{C_{act}}{\begin{pmatrix}
1986  \\
96 \\
22 
\end{pmatrix}}

$$
```

### 7. Scalar Product
Test for multiplying two vectors.
```math
$$
\stackrel{A}{\begin{pmatrix}
13 & 9 & 23 & 1

\end{pmatrix}}

\times

\stackrel{B}{\begin{pmatrix}
2 \\
21 \\
11 \\
62 
\end{pmatrix}}
=

\stackrel{C_{exp}}{\begin{pmatrix}
530 
\end{pmatrix}}

\quad
\quad

\stackrel{C_{act}}{\begin{pmatrix}
1987
\end{pmatrix}}

$$
```

### 8. Comformability
Test for conformability of the two matrices involved in matrix multiplication.

**Expected**: checking the property before carrying out the operation and stopping it.


### 9. Dimension
Test for result matrix dimension
```math
$$
\stackrel{A}{\begin{pmatrix}
3 & 8 & 6 & 5 \\
6 & 3 & 4 & 2 \\
2 & 1 & 8 & 9
\end{pmatrix}}

\times

\stackrel{B}{\begin{pmatrix}
9 & 7 \\
7 & 6 \\
1 & 4 \\
6 & 1
\end{pmatrix}}
=
C_{exp}

$$
```
**Expected**: **C<sub>exp</sub>** as a 3x2 matrix.

### 10. TestEmptyMatrices
Test for multiplying two empty matrices. 
```math
$$
\stackrel{A}{\begin{pmatrix}
\end{pmatrix}}

\times

\stackrel{B}{\begin{pmatrix}
\end{pmatrix}}
=

\stackrel{C_{exp}}{\begin{pmatrix}
 \end{pmatrix}}

\quad
\quad



$$
```

### 12. TestCorrectMatrices
Test for Multiplying two matrices that respect all the constrains found.

```math
$$
\stackrel{A}{\begin{pmatrix}
1 & 2 & 3 & 4
\end{pmatrix}}

\times

\stackrel{B}{\begin{pmatrix}
8 & 7 \\
7 & 5 \\
8 & 7 \\
7 & 5
\end{pmatrix}}
=

\stackrel{C_{exp}}{\begin{pmatrix}
74 & 58
 \end{pmatrix}}

\quad
\quad

\stackrel{C_{act}}{\begin{pmatrix}
74 & 58
\end{pmatrix}}

$$
```

## Summary of the errors:
The errors below are highlighted by the function when prompted, found through the use of tests.

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
13. A row in matrix A is filled entirely with 5s.
14. Matrix B contains the number 3.
15. Result matrix contains a number between 11 and 20.
16. A row in matrix A contains more than one '1'.
17. Result matrix C contains the number 17.
18. Matrix B contains the number 6.



