#include<stdio.h>
#include<iostream>
using namespace std;

class car{
public:
    string brand;
    int price;
    int seats;
};

int main(){
    car c1;
    c1.brand = "BMW";
    c1.price = 50000;
    c1.seats = 4;

    cout<<c1.brand<<" "<<c1.price<<" "<<c1.seats<<endl;

    return 0;
}