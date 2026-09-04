#include<iostream>
using namespace std;
// function in class
class cricter{
public:
    int age;
    string name;
    cricter(int age,string name){
        this->age=age;
        this->name=name;
    }
    void display(){
        cout<<"Name: "<<name<<" "<<"Age: "<<age<<endl;
    }
};

int main()
{
    cricter c1(25,"Virat Kohli");
    c1.display();

    cricter c2(30,"Rohit Sharma");
    c2.display();
    
    return 0;
}