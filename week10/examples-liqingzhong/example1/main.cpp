#include <iostream>
#include "time.hpp"

int main() {
    MyTime t1(2, 40);
    MyTime t2(1, 20);
    std::cout <<(t1 + t2).getTime() << std::endl;

    t1+=t2; // operator
    t1.operator+=(t2); // function

    std::cout << t1.getTime() << std::endl;

    return 0;
}

/*
[root@sdtp-dev example1]# g++ main.cpp -std=c++11
[root@sdtp-dev example1]# ./a.out 
4 hours and 0 minutes.
5 hours and 20 minutes.
[root@sdtp-dev example1]# 
*/