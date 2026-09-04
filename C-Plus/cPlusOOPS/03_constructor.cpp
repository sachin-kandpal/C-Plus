#include<iostream>
using namespace std;
class student{
public:
    string name;
    int age;
    // creating a constructor
    student(string s, int a){
        name = s;
        age = a;
    }
};
int main(){
    student s1("Harry", 24);
    cout<<s1.name<<endl;
    cout<<s1.age<<endl;
    return 0;
}