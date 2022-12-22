#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
T sum(T x, T y) {
    cout << "The input type is " << typeid(T).name() << endl;
    return x + y;
}

int main() {
    // Implicitly instantiates product<int>(int, int)
    cout << "sum = " << sum<int>(2.2f, 3.0f) << endl;

    // Implicitly instantiates product<float>(float, float)
    cout << "sum = " << sum(2.2f, 3.0f) << endl;

    return 0;
}
/*
[root@sdtp-dev examples-liqingzhong]# g++ -g template2.cpp -std=c++11
[root@sdtp-dev examples-liqingzhong]# ./a.out 
The input type is i
sum = 5
The input type is f
sum = 5.2
[root@sdtp-dev examples-liqingzhong]# 
*/