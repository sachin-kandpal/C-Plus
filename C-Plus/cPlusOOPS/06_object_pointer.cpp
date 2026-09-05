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
    void display(){
        cout<<"Name: "<<name<<" "<<"Age: "<<age<<endl;
    }
    void change(cricketer* c1){
        // (*c1).age = 30;
        // (*c1).name = "Rohit Sharma";
        // or we can use arrow operator
        c1->age = 30;
        c1->name = "Rohit Sharma";
    }
};

int main()
{
    cricketer c1(25,"Virat Kohli");
    // c1.display();

    // // Creating object pointer
    // cricketer* p1 = &c1;
    // cout<<c1.age<<endl;
    // cout<<(*p1).age<<endl;
    // or we can use arrow operator
    // cout<<p1->age<<endl;

    // changing the value of object using pointer
    c1.change(&c1);
    c1.display();
    return 0;
}