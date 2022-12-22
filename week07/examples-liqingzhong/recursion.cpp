#include <iostream>

using namespace std;

void div2(double val);

int main() {
    
    div2(1024.); // call the recursion function
    
    return 0;
}

void div2(double val) {
    cout << "Entering val = " << val << endl;
    if (val > 1.0) {
        div2( val / 2); // function calls itself
    } else {
        cout <<  "------------------------" << endl;
    }
    
    cout << "Leaving val = " << val << endl;
}

/*
[root@sdtp-dev examples-liqingzhong]# g++ -g recursion.cpp -std=c++11
[root@sdtp-dev examples-liqingzhong]# ./a.out 
Entering val = 1024
Entering val = 512
Entering val = 256
Entering val = 128
Entering val = 64
Entering val = 32
Entering val = 16
Entering val = 8
Entering val = 4
Entering val = 2
Entering val = 1
------------------------
Leaving val = 1
Leaving val = 2
Leaving val = 4
Leaving val = 8
Leaving val = 16
Leaving val = 32
Leaving val = 64
Leaving val = 128
Leaving val = 256
Leaving val = 512
Leaving val = 1024
[root@sdtp-dev examples-liqingzhong]# 
*/