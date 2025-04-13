#include <iostream>
using namespace std;

// Compile Time Polymorphism
class Print {
public:
    // Function Overloading
    void show(int x) {
        cout << "int: " << x << endl;
    }
    void show(string str) {
        cout << "str: " << str << endl;
    }
};

class Complex {
    int real;
    int img;
public:
    Complex(int r, int i){
        real = r;
        img = i;
    }
    void showNum() {
        cout << real << " + " << img << "i" << endl;
    }
    // Operator Overloading
    Complex operator + (Complex &c2){
        int resReal = this->real + c2.real;
        int resImg = this->img + c2.img;
        Complex c3(resReal, resImg);
        return c3;
    }
    Complex operator - (Complex &c2){
        int resReal = this->real - c2.real;
        int resImg = this->img - c2.img;
        Complex c3(resReal, resImg);
        return c3;
    }
};

// Runtime Polymorphism
class Parent {
public:
    void show() {
        cout << "parent class show..." << endl;
    }
    // Virtual Function
    virtual void hello() {
        cout << "parent class hello..." << endl;
    }
};

class Child : public Parent {
public:
    // Function Overriding
    void show() {
        cout << "child class show..." << endl;
    } 
    void hello() {
        cout << "child class hello..." << endl;
    }
};

int main() {
    // Function Overlaoading
    Print obj1;
    obj1.show(25);
    obj1.show("Hello");

    // Operator Overloading
    Complex c1(1, 2);
    Complex c2(3, 4);

    c1.showNum();
    c2.showNum();
    Complex c3 = c1 + c2;
    c3.showNum();
    Complex c4 = c1 - c2;
    c4.showNum();

    // Function Overriding
    Child child1;
    child1.show();
    // Virtual Function
    Parent *ptr;
    ptr = &child1; // Runtime Binding
    ptr->hello();  // child class hello... 

    return 0;
}