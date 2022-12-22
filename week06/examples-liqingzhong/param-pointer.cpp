#include <iostream>

using namespace std;

int foo1(int x) {
    x += 10;
    return x;
}

int foo2(int * p) {
    (*p) +=10;
    return *p;
}

int main() {
    int num1 = 20;
    int num2 = foo1(num1);
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    int * p = &num1;
    int num3 = foo2(p);
    cout << "num1 = " << num1 << endl;
    cout << "*p = " << *p << endl;
    cout << "num3 = " << num3 << endl;

    return 0;
}

/*
[root@sdtp-dev examples-liqingzhong]# g++ -g param-pointer.cpp 
[root@sdtp-dev examples-liqingzhong]# ./a.out 
num1 = 20
num2 = 30
num1 = 30
*p = 30
num3 = 30
[root@sdtp-dev examples-liqingzhong]# 
*/