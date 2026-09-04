#include<iostream>
using namespace std;
class cricter{
public:
    int age;
    string name;
    cricter(int age,string name){
        // this pointer is used to refer the current object of the class. It is used to access the members of the current object.
        this->age=age;
        this->name=name;
    }
};

int main()
{
    cricter c1(25,"Virat Kohli");
    cout<<"Name: "<<c1.name<<" "<<"Age: "<<c1.age<<endl;

    cricter c2(30,"Rohit Sharma");
    cout<<"Name: "<<c2.name<<" "<<"Age: "<<c2.age<<endl;
    
    return 0;
}