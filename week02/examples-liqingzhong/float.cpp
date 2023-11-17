#include <iostream>
#include <iomanip>

int main() {
    float a = 1.2f;
    float b = a * 1000000000000000;
    std::cout << std::fixed << std::setprecision(15) << a << std::endl;
    std::cout << std::fixed << std::setprecision(15) << b << std::endl;
}

/*
[root@sdtp examples-liqingzhong]# g++ -o float float.cpp 
[root@sdtp examples-liqingzhong]# ./float 
1.200000047683716
1200000038076416.000000000000000
[root@sdtp examples-liqingzhong]# 
*/