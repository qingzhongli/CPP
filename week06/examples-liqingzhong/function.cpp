#include <iostream>
#include <float.h>

struct Matrix {
    int rows;
    int cols;
    float * pData;
};

float matrix_max(struct Matrix mat) {
    float max = FLT_MIN;
    // find max value of mat
    for (int r = 0; r < mat.rows; r++) {
        for (int c = 0; c < mat.cols; c++) {
            float val = mat.pData[r * mat.cols + c];
            std::cout << "(" << r << ", " << c << ") = " << val << std::endl;
            max = (max > val ? max : val);
        }
    }
    return max;
}

Matrix * create_matrix(int rows, int cols) {
    Matrix * p = new Matrix{rows, cols};
    p -> pData = new float[p->rows * p->cols]{1.f, 2.f, 3.f};
    // you should check if the memory is allocated successfully
    return p;
}

bool matrix_add(const Matrix &matA, const Matrix &matB, Matrix &matC) {
    // check the dimensions of three matrices
    // re-create matC if needed
    // do : matC = matA + matB
    // return true if everything is right
    return true;
}

int main() {
    using namespace std;

    Matrix matA = {3, 4};
    matA.pData = new float[matA.rows * matA.cols]{1.f, 2.f, 3.f};

    Matrix matB = {4, 8};
    matB.pData = new float[matB.rows * matB.cols]{10.f, 20.f, 30.f};

    Matrix matC = {4, 2};
    matC.pData = new float[matC.rows * matC.cols]{100.f, 200.f, 300.f};

    // some operation on the matrices

    float maxa = matrix_max(matA);
    cout << "max(matA) = " << maxa << endl;
    
    float maxb = matrix_max(matB);
    cout << "max(matB) = " << maxb << endl;

    float maxc = matrix_max(matC);
    cout << "max(matC) = " << maxc << endl;
    
    delete [] matA.pData;
    delete [] matB.pData;
    delete [] matC.pData;

    return 0;
}

/*
[root@sdtp-dev examples-liqingzhong]# g++ -g function.cpp -std=c++11
function.cpp: In function ‘Matrix* create_matrix(int, int)’:
function.cpp:25:60: warning: non-constant array size in new, unable to verify length of initializer-list [enabled by default]
     p -> pData = new float[p->rows * p->cols]{1.f, 2.f, 3.f};
                                                            ^
function.cpp: In function ‘int main()’:
function.cpp:42:64: warning: non-constant array size in new, unable to verify length of initializer-list [enabled by default]
     matA.pData = new float[matA.rows * matA.cols]{1.f, 2.f, 3.f};
                                                                ^
function.cpp:45:67: warning: non-constant array size in new, unable to verify length of initializer-list [enabled by default]
     matB.pData = new float[matB.rows * matB.cols]{10.f, 20.f, 30.f};
                                                                   ^
function.cpp:48:70: warning: non-constant array size in new, unable to verify length of initializer-list [enabled by default]
     matC.pData = new float[matC.rows * matC.cols]{100.f, 200.f, 300.f};
                                                                      ^
[root@sdtp-dev examples-liqingzhong]# ./a.out 
(0, 0) = 1
(0, 1) = 2
(0, 2) = 3
(0, 3) = 0
(1, 0) = 0
(1, 1) = 0
(1, 2) = 0
(1, 3) = 0
(2, 0) = 0
(2, 1) = 0
(2, 2) = 0
(2, 3) = 0
max(matA) = 3
(0, 0) = 10
(0, 1) = 20
(0, 2) = 30
(0, 3) = 0
(0, 4) = 0
(0, 5) = 0
(0, 6) = 0
(0, 7) = 0
(1, 0) = 0
(1, 1) = 0
(1, 2) = 0
(1, 3) = 0
(1, 4) = 0
(1, 5) = 0
(1, 6) = 0
(1, 7) = 0
(2, 0) = 0
(2, 1) = 0
(2, 2) = 0
(2, 3) = 0
(2, 4) = 0
(2, 5) = 0
(2, 6) = 0
(2, 7) = 0
(3, 0) = 0
(3, 1) = 0
(3, 2) = 0
(3, 3) = 0
(3, 4) = 0
(3, 5) = 0
(3, 6) = 0
(3, 7) = 0
max(matB) = 30
(0, 0) = 100
(0, 1) = 200
(1, 0) = 300
(1, 1) = 0
(2, 0) = 0
(2, 1) = 0
(3, 0) = 0
(3, 1) = 0
max(matC) = 300
[root@sdtp-dev examples-liqingzhong]# 
*/