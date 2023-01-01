#include "student.hpp"

int main() {
    Student yu;
    yu.setName("Yu");
    yu.setBorn(2000);
    yu.setGender(true);
    yu.printInfo();

    return 0;
}

/*
[root@sdtp-dev multi-files]# mkdir build
[root@sdtp-dev multi-files]# cd build
[root@sdtp-dev build]# cmake ..
-- The C compiler identification is GNU 4.8.5
-- The CXX compiler identification is GNU 4.8.5
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /root/github.com/qingzhongli/CPP/week09/examples-liqingzhong/multi-files/build
[root@sdtp-dev build]# make
Scanning dependencies of target studentdemo
[ 33%] Building CXX object CMakeFiles/studentdemo.dir/main.cpp.o
[ 66%] Building CXX object CMakeFiles/studentdemo.dir/student.cpp.o
[100%] Linking CXX executable studentdemo
[100%] Built target studentdemo
[root@sdtp-dev build]# ./studentdemo 
Name: Yu
Born in 2000
Gender: Male
[root@sdtp-dev build]# 
*/