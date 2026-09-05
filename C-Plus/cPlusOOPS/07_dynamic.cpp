#include<iostream>
using namespace std;
// function in class
class cricketer{
public:
    int age;
    string name;
    cricketer(int age,string name){
        this->age=age;
        this->name=name;
    }   
    // void display(){
    //     cout<<"Name: "<<name<<" "<<"Age: "<<age<<endl;
    // }

};

int main()
{
    cricketer c1(25,"Virat Kohli");
    cricketer* c2 = new cricketer(30,"Rohit Sharma");
    // c1.display();
    cout<<c2->age<<""<<c2->name<<endl;
    
    // dynamically allocating memory for an integer
    int* ptr = new int(10);
    cout<<*ptr<<endl;

    // Don't forget to free the dynamically allocated memory
    delete ptr;

    return 0;
}