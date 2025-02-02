#include <iostream>
#include <cmath>

using namespace std;

float norm_l1(float x, float y); //declaration
float norm_l2(float x, float y); //declaration
float (*norm_ptr)(float x, float y); // norm_ptr is function pointer

int main() {
    norm_ptr = norm_l1; // Pointer norm_ptr is pointing to norm_l1
    cout << "L1 norm of (-3, 4) = " << norm_ptr(-3.0f, 4.0f)<< endl;

    norm_ptr = &norm_l2; // Pointer norm_ptr is pointing norm_l2
    cout << "L2 norm of (-3, 4) = " << (*norm_ptr)(-3.0f, 4.0f) << endl;

    return 0;
}

float norm_l1(float x, float y) { 
    return fabs(x) + fabs(y);
}

float norm_l2(float x, float y) {
    return sqrt(x * x + y * y);
}

/*
[root@sdtp-dev examples]# g++ -g function-pointer.cpp 
[root@sdtp-dev examples]# ./a.out 
L1 norm of (-3, 4) = 7
L2 norm of (-3, 4) = 5
[root@sdtp-dev examples]# g++ -g function-pointer.cpp -std=c++11
[root@sdtp-dev examples]# ./a.out  
L1 norm of (-3, 4) = 7
L2 norm of (-3, 4) = 5
[root@sdtp-dev examples]# 
*/