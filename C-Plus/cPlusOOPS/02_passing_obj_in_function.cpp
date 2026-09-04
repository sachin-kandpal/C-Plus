#include<iostream>
using namespace std;

class car{
public:
    string brand;
    int price;
    int seats;
};

// pass by value hota h ye 
// car& c likhne se pass by reference hota h
void printCarDetails(car c){
    cout<<c.brand<<" "<<c.price<<" "<<c.seats<<endl;
}

int main(){
    car c1;
    c1.brand = "BMW";
    c1.price = 50000;
    c1.seats = 4;

    car c2;
    c2.brand = "Audi";
    c2.price = 60000;
    c2.seats = 4;

    car c3;
    c3.brand = "Mercedes";
    c3.price = 70000;
    c3.seats = 4;

    printCarDetails(c1);
    printCarDetails(c2);
    printCarDetails(c3);

    return 0;
}