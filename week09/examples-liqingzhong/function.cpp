#include <iostream>
#include <cstring>

class Student {
    private:
        char name[4];
        int born;
        bool male;

    public:
        void setName(const char * s) {
            strncpy(name, s, sizeof(name));
        }

        void setBorn(int b) {
            born = b;
        }

        // the declaraions, the definations are out of the class
        void setGender(bool isMale);

        void printInfo();
};

void Student::setGender(bool isMale) {
    male = isMale;
}

void Student::printInfo() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Born in " << born << std::endl;
    std::cout << "Gender: " << (male ? "Male" : "Female") << std::endl;
}

int main() {
    Student yu;
    yu.setName("Yu");
    yu.setBorn(2000);
    yu.setGender(true);
    yu.printInfo();

    return 0;
}

/*
root@sdtp-dev examples-liqingzhong]# g++ -g function.cpp 
[root@sdtp-dev examples-liqingzhong]# ./a.out 
Name: Yu
Born in 2000
Gender: Male
[root@sdtp-dev examples-liqingzhong]# 
*/