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
            cout << "Constructor: Person()" << endl;
        }

        Student(const char * initName, int initBorn, bool isMale) {
            name = new char[1024];
            setName(initName);
            born = initBorn;
            male = isMale;
            cout << "Constructor: Person(const char, int, bool)" << endl;
        }

        ~Student() {
            cout << "To destroy object: " << name << endl;
            delete [] name;
        }

        void setName(const char * s) {
            strncpy(name, s, 1024);
        }

        void setBorn(int b) {
            born = b;
        }

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

    Student * class1 = new Student[3] {
        {"Tom", 2000, true},
        {"Bob", 2001, true},
        {"Amy", 2002, false}
    };

    class1[1].printInfo();
    // Use the array syntax to delete the array of objects.
    delete []class1;
    
    // delete class1; // memory leak

    // https://cplusplus.com/reference/new/operator%20delete%5b%5d
    // https://learn.microsoft.com/en-us/cpp/cpp/delete-operator-cpp?view=msvc-170

    return 0;
}

/*
[root@sdtp-dev examples-liqingzhong]# g++ -g array.cpp -std=c++11
[root@sdtp-dev examples-liqingzhong]# ./a.out 
Constructor: Person(const char, int, bool)
Constructor: Person(const char, int, bool)
Constructor: Person(const char, int, bool)
Name: Bob
Born in 2001
Gender: Male
To destroy object: Amy
To destroy object: Bob
To destroy object: Tom
[root@sdtp-dev examples-liqingzhong]# 
*/