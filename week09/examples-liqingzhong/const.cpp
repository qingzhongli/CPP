#include <iostream>
#include <cstring>

using namespace std;

class Student {
    private:
        const int BMI = 24;
        char * name;
        int born;
        bool male;
    public:
        Student() {
            name = new char[1024]{0};
            born = 0;
            male = false;
            //BMI = 25; // cannot be modified
            cout << "Constructor: Student()" << endl;
        }

        Student(const char * name, int born, bool male) {
            this->name = new char[1024];
            setName(name);
            this->born = born;
            this->male = male;
            cout << "Constructor: Student(const char, int, bool)" << endl;
        }

        ~Student() {
            cout << "To destroy object: " << name << endl;
            delete [] name;
        }

        void setName(const char * name) {
            strncpy(this->name, name, 1024);
        }

        void setBorn(int born) {
            this->born = born;
        }

        int getBorn() const {
            //born++; // cannot be modified
            return born;
        }

        // the declarations, the definitions are out of class
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
    Student yu("Yu", 2000, true);
    cout << "yu.getBorn() = " << yu.getBorn() << endl;
    return 0;
}

/*
[root@sdtp-dev examples-liqingzhong]# g++ -g const.cpp -std=c++11
[root@sdtp-dev examples-liqingzhong]# ./a.out 
Constructor: Student(const char, int, bool)
yu.getBorn() = 2000
To destroy object: Yu
[root@sdtp-dev examples-liqingzhong]# 
*/