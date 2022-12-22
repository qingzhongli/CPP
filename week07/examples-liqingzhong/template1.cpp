#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
T sum(T x, T y) {
    cout << "The input type is " << typeid(T).name() << endl;
    return x + y;
}

// Explicitly instantiate
template double sum<double>(double, double);

template int sum<int>(int, int);

int main() {
    
    auto val = sum(4.1, 5.2);
    cout << val << endl;
    
    auto val2 = sum(2, 3);
    cout << val2 << endl;

    return 0;
}

/*
[root@sdtp-dev examples-liqingzhong]# g++ -g template1.cpp -std=c++11
[root@sdtp-dev examples-liqingzhong]# ./a.out 
The input type is d
9.3
The input type is i
5
[root@sdtp-dev examples-liqingzhong]# 
*/