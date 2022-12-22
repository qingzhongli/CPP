#include <iostream>
#include <cmath>

using namespace std;

float norm(float x, float y, float z);
float norm(float x, float y, float z = 0);
float norm(float x, float y = 0, float z);

int main()
{
    cout << norm(3.0f) << endl;
    cout << norm(3.0f, 4.0f) << endl;
    cout << norm(3.0f, 4.0f, 5.0f) << endl;
    return 0;
}

float norm(float x, float y, float z)
{
    return sqrt(x * x + y * y + z * z);
}

/*
[root@sdtp-dev examples]# g++ -g default-argument.cpp 
[root@sdtp-dev examples]# ./a.out 
3
5
7.07107
[root@sdtp-dev examples]# g++ -g default-argument.cpp -std=c++11
[root@sdtp-dev examples]# ./a.out 
3
5
7.07107
[root@sdtp-dev examples]# 
*/