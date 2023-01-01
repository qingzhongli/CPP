#include <iostream>
#include "time.hpp"

int main() {
    MyTime t1(2, 40);
    std::cout << (30 + t1).getTime() << std::endl;

    std::cout << t1 << std::endl;
    std::cout << "Please input two integers:" << std::endl;
    std::cin >> t1;
    std::cout << t1 << std::endl;

    return 0;
}

/*
[root@sdtp-dev example3]# g++ -g main.cpp -std=c++11
[root@sdtp-dev example3]# ./a.out 
3 hours and 10 minutes.
2 hours and 40 minutes;
Please input two integers:
10 20
10 hours and 20 minutes;
[root@sdtp-dev example3]# 
*/