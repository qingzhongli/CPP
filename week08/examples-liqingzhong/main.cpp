#include <iostream>
#include <cstdlib>
#include <chrono>
#include "matoperation.hpp"

using namespace std;

#define TIME_START start=std::chrono::steady_clock::now();
#define TIME_END(NAME) end=std::chrono::steady_clock::now(); \
            duration=std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); \
            cout <<(NAME)<<": result="<<result \
            <<", duration = "<<duration<<"ms"<<endl;

int main(int argc, char **argv) {

    size_t nSize = 200000000;
    //float * p1 = new float[nSize](); //the memory is not aligned
    //float * p2 = new float[nSize](); //the memory is not aligned

    //256bits aligned, C++17 standard
    float * p1 = static_cast<float*>(aligned_alloc(256, nSize*sizeof(float)));
    float * p2 = static_cast<float*>(aligned_alloc(256, nSize*sizeof(float)));
    float result = 0.0f;

    p1[2] = 2.3f;
    p2[2] = 3.0f;
    p1[nSize - 1] = 2.0f;
    p2[nSize - 1] = 1.1f;

    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    auto duration = 0L;

    result = dotproduct(p1, p2, nSize);
    result = dotproduct(p1, p2, nSize);

    TIME_START
    result = dotproduct(p1, p2, nSize);
    TIME_END("normal")

    TIME_START
    result = dotproduct_unloop(p1, p2, nSize);
    TIME_END("unloop")

    TIME_START
    result = dotproduct_avx2(p1, p2, nSize);
    TIME_END("SIMD")

    TIME_START
    result = dotproduct_avx2_omp(p1, p2, nSize);
    TIME_END("SIMD+OpenMP")

    delete []p1;
    delete []p2;

    return 0;
}

/*
[root@sdtp-dev examples-liqingzhong]# gcc -mavx2 -dM -E - < /dev/null | egrep "SSE|AVX" | sort
#define __AVX__ 1
#define __AVX2__ 1
#define __SSE__ 1
#define __SSE2__ 1
#define __SSE2_MATH__ 1
#define __SSE3__ 1
#define __SSE4_1__ 1
#define __SSE4_2__ 1
#define __SSE_MATH__ 1
#define __SSSE3__ 1
[root@sdtp-dev examples-liqingzhong]# 
[root@sdtp-dev examples-liqingzhong]# mkdir build
[root@sdtp-dev examples-liqingzhong]# cd build
[root@sdtp-dev build]# cmake .. 
-- The C compiler identification is GNU 4.8.5
-- The CXX compiler identification is GNU 4.8.5
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Try OpenMP C flag = [-fopenmp]
-- Performing Test OpenMP_FLAG_DETECTED
-- Performing Test OpenMP_FLAG_DETECTED - Success
-- Try OpenMP CXX flag = [-fopenmp]
-- Performing Test OpenMP_FLAG_DETECTED
-- Performing Test OpenMP_FLAG_DETECTED - Success
-- Found OpenMP: -fopenmp  
-- Configuring done
-- Generating done
-- Build files have been written to: /root/github.com/qingzhongli/CPP/week08/examples-liqingzhong/build
[root@sdtp-dev build]# make
Scanning dependencies of target dotp
[ 33%] Building CXX object CMakeFiles/dotp.dir/main.cpp.o
[ 66%] Building CXX object CMakeFiles/dotp.dir/matoperation.cpp.o
[100%] Linking CXX executable dotp
[100%] Built target dotp
[root@sdtp-dev build]# ./dotp 
normal: result=9.1, duration = 480ms
unloop: result=9.1, duration = 472ms
SIMD: result=9.1, duration = 107ms
SIMD+OpenMP: result=9.1, duration = 112ms
[root@sdtp-dev build]# ./dotp 
normal: result=9.1, duration = 472ms
unloop: result=9.1, duration = 469ms
SIMD: result=9.1, duration = 113ms
SIMD+OpenMP: result=9.1, duration = 116ms
[root@sdtp-dev build]# ./dotp 
normal: result=9.1, duration = 469ms
unloop: result=9.1, duration = 463ms
SIMD: result=9.1, duration = 110ms
SIMD+OpenMP: result=9.1, duration = 109ms
[root@sdtp-dev build]# 
*/