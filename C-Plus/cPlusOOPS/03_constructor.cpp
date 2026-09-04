#include<iostream>
using namespace std;
class student{
public:
    string name;
    int age;
    // creating a constructor
    // parameterized constructor
    student(string s, int a){
        name = s;
        age = a;
    }
    // default constructor
    student(){
    }
};
int main(){
    // creating object of student class using parameterized constructor
    student s1("Harry", 24);
    cout<<s1.name<<endl;
    cout<<s1.age<<endl;

    // creating object of student class using default constructor
    student s2;
    s2.name = "Ron";
    s2.age = 25;
    cout<<s2.name<<endl;
    cout<<s2.age<<endl;

    // copy constructor
    // deep copy hota h ye
    student s3 = s1; 
    cout<<s3.name<<endl;
    cout<<s3.age<<endl;
    
    // deep copy hota h ye bhi
    student s4(s2);
    cout<<s4.name<<endl;
    cout<<s4.age<<endl;

    return 0;
}