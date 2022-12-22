#include <iostream>

using namespace std;

int sum(int x, int y) {
    cout << "sum(int, int) is called" << endl;
    return x + y;
}

float sum(float x, float y) {
    cout<< "sum(float, float) is called" << endl;
    return x + y;
}

double sum(double x, double y) {
    cout << "sum(double, double) is called" << endl;
    return x + y;
}

// // Is the following definition correct? --> correct
// double sum(int x, int y) {
//     cout << "sum(int, int) is called" << endl;
//     return x + y;
// }

int main() {

    cout << "sum = " << sum(1, 2) << endl;
    cout << "sum = " << sum(1.1f, 2.2f) << endl;
    cout << "sum = " << sum(1.1, 2.2) << endl;

    // which function will eb called? --> error: call of overloaded ‘sum(int, double)’ is ambiguous
    // cout << "sum = " << sum(1, 2.2) << endl;

    return 0;
}

/*
[root@sdtp-dev examples-liqingzhong]# g++ -g overload.cpp  -std=c++11
overload.cpp: In function ‘int main()’:
overload.cpp:33:35: error: call of overloaded ‘sum(int, double)’ is ambiguous
     cout << "sum = " << sum(1, 2.2) << endl;
                                   ^
overload.cpp:33:35: note: candidates are:
overload.cpp:5:5: note: int sum(int, int)
 int sum(int x, int y) {
     ^
overload.cpp:10:7: note: float sum(float, float)
 float sum(float x, float y) {
       ^
overload.cpp:15:8: note: double sum(double, double)
 double sum(double x, double y) {
        ^
[root@sdtp-dev examples-liqingzhong]# g++ -g overload.cpp  -std=c++11
[root@sdtp-dev examples-liqingzhong]# ./a.out 
sum(int, int) is called
sum = 3
sum(float, float) is called
sum = 3.3
sum(double, double) is called
sum = 3.3
[root@sdtp-dev examples-liqingzhong]# g++ -g overload.cpp  
[root@sdtp-dev examples-liqingzhong]# ./a.out 
sum(int, int) is called
sum = 3
sum(float, float) is called
sum = 3.3
sum(double, double) is called
sum = 3.3
[root@sdtp-dev examples-liqingzhong]# 
*/