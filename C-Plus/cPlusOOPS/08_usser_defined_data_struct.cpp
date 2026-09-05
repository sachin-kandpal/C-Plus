// making my ownn data structure vector
#include <iostream>
using namespace std;

class Vector {
public:
    int size;
    int capacity;
    int* arr;
    Vector(){
        size = 0;
        capacity = 1;
        arr = new int[capacity];
    }
    void add(int value) {
        if (size >= capacity) {
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size] = value;
        size++;
    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int get(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            cout << "Index out of bounds" << endl;
            return -1; // or throw an exception
        }
    }
    void pop() {
        if (size > 0) {
            size--;
        } else {
            cout << "Vector is empty" << endl;
        }
    }
};
int main() {
    Vector v1;
    cout << "Size:"<<v1.size<<" "<<"Capacity:"<<v1.capacity<<endl;
    v1.add(10);
    v1.print();
    cout << "Size:"<<v1.size<<" "<<"Capacity:"<<v1.capacity<<endl;
    v1.add(20);
    v1.print();
    cout << "Size:"<<v1.size<<" "<<"Capacity:"<<v1.capacity<<endl;
    v1.add(30);
    v1.print();
    cout << "Size:"<<v1.size<<" "<<"Capacity:"<<v1.capacity<<endl;

    cout << "Element at index 1: " << v1.get(1) << endl;
    
    v1.pop();
    v1.print();
    return 0;
}