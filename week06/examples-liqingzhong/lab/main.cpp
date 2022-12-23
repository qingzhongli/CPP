#include <iostream>
//#include <mymath.h>
//#include <> // 是用来载入libc库中的头文件的，一般不会在当前目录查询有无对应名称的头文件
//#include "" // 是用来载入自己编写或者不在libc库中的头文件的。
#include "mymath.h"
/*
C++ 中include头文件时尖括号与双引号的区别
1 区别
系统自带的头文件用尖括号括起来，表示编译器先在用户的工作目录下搜索头文件，
如果搜索不到则到系统默认目录下去寻找，所以双引号一般用于包含用户自己编写
的头文件。如：#include “student.h” , #include “XXXX.h” 。

用户自定义的文件用双引号括起来，编译器首先会在用户目录下查找，然后在到C++
安装目录（比如VC中可以指定和修改库文件查找路径，Unix和Linux中可以通过环境变量来设定）中查找。
所以一般尖括号用于包含标准库文件，如：#include <stdio.h>, #include<stdlib.h>

2 总结
使用 “xxx.h”,告诉编译器,从当前工作目录开始查找。
使用<xxx.h>,告诉编译器,从系统默认目录中去查找；
当不确定的时候,就使用双引号,系统会从当前工作目录找完成后,然后再去系统默认目录中查找。
若 #include “” 查找成功，则遮蔽 #include <> 所能找到的同名文件；否则再按照 #include <> 的方式查找文件。
另外标准库头文件都放在 #include <> 所查找的位置
————————————————
版权声明：本文为CSDN博主「zou_albert」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/zou_albert/article/details/107349429
*/
int main() {
    int x = 10;
    int y = 20;
    int z = add(x, y);

    std::cout << "z = " << z << std::endl;

    return 0;
}

/*
[root@sdtp-dev lab]# g++ -g main.cpp mymath.cpp -std=c++11
[root@sdtp-dev lab]# ./a.out 
z = 30
[root@sdtp-dev lab]# 
*/