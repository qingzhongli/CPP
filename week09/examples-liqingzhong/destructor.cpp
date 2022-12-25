#include <iostream>
#include <cstring>

using namespace std;

class Student {
    private:
        char * name;
        int born;
        bool male;
    public:
        Student() {
            name = new char[1024]{0};
            born = 0;
            male = false;
            cout << "Constructor: Student()" << endl;
        }

        Student(const char * initName, int initBorn, bool isMale) {
            name = new char[1024];
            setName(initName);
            born = initBorn;
            male = isMale;
            cout << "Constructor: Student(Const char, int, bool)" << endl;            
        }

        ~Student() {
            cout << "To destroy object: " << name << endl;
            delete []name;
        }

        void setName(const char * s) {
            strncpy(name, s, 1024);
        }

        void setBorn(int b) {
            born = b;
        }

        // the declarations, the definiation are out of the class
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
    {
        Student yu;
        yu.printInfo();

        yu.setName("Yu");
        yu.setBorn(2000);
        yu.setGender(true);
        yu.printInfo();
    }

    Student xue = Student("XueQikun", 1962, true);
    xue.printInfo();

    Student * zhou = new Student("Zhou", 1991, false);
    zhou->printInfo();
    delete zhou;

    return 0;
}

/*
[root@sdtp-dev examples-liqingzhong]# g++ -g destructor.cpp -std=c++11
[root@sdtp-dev examples-liqingzhong]# ./a.out 
Constructor: Student()
Name: 
Born in 0
Gender: Female
Name: Yu
Born in 2000
Gender: Male
To destroy object: Yu
Constructor: Student(Const char, int, bool)
Name: XueQikun
Born in 1962
Gender: Male
Constructor: Student(Const char, int, bool)
Name: Zhou
Born in 1991
Gender: Female
To destroy object: Zhou
To destroy object: XueQikun
[root@sdtp-dev examples-liqingzhong]# 
*/