#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
T sum(T x, T y) {
    cout << "The input type is " << typeid(T).name() << endl;
    return x + y;
}

struct Point {
    int x;
    int y;
};

template<> 
Point sum<Point>(Point pt1, Point pt2) {
    cout << "The input type is " << typeid(pt1).name() << endl;
    Point pt;
    pt.x = pt1.x + pt2.x;
    pt.y = pt1.y + pt2.y;
    return pt;
}

int main() {
    // Implicit instantiated functions
    cout << "sum = " << sum(1, 2) << endl;
    cout << "sum = " << sum(1.1, 2.2) << endl;

    Point pt1 {1, 2};
    Point pt2 {2, 3};
    Point pt = sum(pt1, pt2);
    cout << "pt = (" << pt.x << ", " << pt.y << ")" << endl;
    return 0;
}

/*
[root@sdtp-dev examples-liqingzhong]# g++ -g specialization.cpp 
specialization.cpp: In function ‘int main()’:
specialization.cpp:31:11: warning: extended initializer lists only available with -std=c++11 or -std=gnu++11 [enabled by default]
     Point pt1 {1, 2};
           ^
specialization.cpp:32:11: warning: extended initializer lists only available with -std=c++11 or -std=gnu++11 [enabled by default]
     Point pt2 {2, 3};
           ^
[root@sdtp-dev examples-liqingzhong]# g++ -g specialization.cpp -std=c++11
[root@sdtp-dev examples-liqingzhong]# ./a.out 
The input type is i
sum = 3
The input type is d
sum = 3.3
The input type is 5Point
pt = (3, 5)
[root@sdtp-dev examples-liqingzhong]# 
*/