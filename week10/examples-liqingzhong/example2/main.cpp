#include <iostream>
#include "time.hpp"

int main() {
    MyTime t1(2, 40);
    std::cout << (t1 + 30).getTime() << std::endl;

    t1 += 30; // operator
    t1.operator+(30); // function

    std::cout << t1.getTime() << std::endl;

    std::cout << (t1 + "one hour").getTime() << std::endl;
    std::cout << (t1 + "two hour").getTime() << std::endl;

    return 0;

}


/*
[root@sdtp-dev examples2]# g++ -g main.cpp -std=c++11
[root@sdtp-dev examples2]# ./a.out 
3 hours and 10 minutes.
3 hours and 10 minutes.
4 hours and 10 minutes.
Only "one hour" is supported.
3 hours and 10 minutes.
[root@sdtp-dev examples2]# 
*/