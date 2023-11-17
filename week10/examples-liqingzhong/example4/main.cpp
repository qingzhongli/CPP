#include <iostream>
#include "time.hpp"

using namespace std;

int main() {
    MyTime t1(1, 20);
    int minutes = t1; // implicit conversion
    float f = float(t1); // explicit conversion
    std::cout << "minutes = " << minutes << std::endl;
    std::cout << "minutes = " << f << std::endl;

    MyTime t2 = 70;
    std::cout << "t2 is " << t2 << std::endl;

    MyTime t3;
    t3 = 80;
    std::cout << "t3 is " << t3 << std::endl;

    return 0;
}

/*
[root@sdtp-dev example4]# g++ main.cpp -std=c++11
[root@sdtp-dev example4]# ./a.out 
Constructor MyTime(int,int)
operator int()
explicit operator float()
minutes = 80
minutes = 80
Constructor MyTime(int)
t2 is 1 hours and 10 minutes 
Constructor MyTime()
operator=(int)
t3 is 1 hours and 20 minutes 
[root@sdtp-dev example4]# 
*/