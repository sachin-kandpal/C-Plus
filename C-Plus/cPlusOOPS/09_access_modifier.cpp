#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int age;
    
    Student(string n, int a, float g) {
        name = n;
        age = a;
        gpa = g;
    }
    // getter for gpa
    float getGPA() {
        return gpa;
    }

    // setter for gpa
    void setGPA(float g) {
        gpa = g;
    }
private:
    float gpa;


};
int main() {
    Student s1("John", 20, 3.5);
    cout << "Name: " << s1.name << endl;
    cout << "Age: " << s1.age << endl;
    cout << "GPA: " << s1.getGPA() << endl; // Accessing private member through getter
    s1.setGPA(3.8); // Updating private member through setter
    cout << "Updated GPA: " << s1.getGPA() << endl;
    return 0;
}