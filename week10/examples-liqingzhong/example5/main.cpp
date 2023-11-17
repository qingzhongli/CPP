#include <iostream>
#include "time.hpp"

int main() {

    MyTime t1(1, 59);
    MyTime t2 = t1++;
    MyTime t3 = ++t1;

    std::cout << "t1 is " << t1 << std::endl;
    std::cout << "t2 is " << t2 << std::endl;
    std::cout << "t3 is " << t3 << std::endl;

    return 0;
}

/*
[root@sdtp-dev example5]# g++ main.cpp -std=c++11
[root@sdtp-dev example5]# ./a.out 
Constructor MyTime(int,int)
t1 is 2 housrs and 1 minutes
t2 is 1 housrs and 59 minutes
t3 is 2 housrs and 1 minutes
[root@sdtp-dev example5]# 
*/