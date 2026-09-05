#include <iostream>
using namespace std;
class scooty {
public:
    string brand;
    int price;

    scooty(string b, int p) {
        brand = b;
        price = p;
    }
};
class bike : public scooty {
public:
    int mileage;

    bike(string b, int p, int m) : scooty(b, p) {
        mileage = m;
    }
};
int main() {
    bike b1("Honda", 80000, 60);
    cout << "Brand: " << b1.brand << endl;
    cout << "Price: " << b1.price << endl;
    cout << "Mileage: " << b1.mileage << endl;
    return 0;
} 