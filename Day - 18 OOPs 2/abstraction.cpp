#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Abstract Function or Pure Virtual Function
};

class Circle : public Shape{
public:
    void draw() {
        cout << "draw circle" << endl;
    }
};

class Square : public Shape{
public:
    void draw() {
        cout << "draw square" << endl;
    }
};

void counter() {
    static int count = 0;
    count++;
    cout << "Count: " << count << endl;
}

class Example {
public:
    // Static Variable
    static int x;

    // Static Object
    Example(){
        cout << "constructor..." << endl;
    }
    ~Example(){
        cout << "destructor..." << endl;
    }
};

int Example::x = 0;

// Friend Class & Friend Function
class A {
    string secret = "Secret Data";
    friend class B;                   // Friend Class
    friend void revealSecret(A &obj); // Friend Function
};

class B { // becomes a friend class of A
public:
    void showSecret(A &obj) {
        cout << obj.secret << endl;
    }
};

void revealSecret(A &obj) { // becomes a friend function of A
    cout << obj.secret << endl;
}

// Practice Questions
// Question 1
class X {
public:
    X() {cout << "Constructor X" << endl;}
    ~X() {cout << "Destructor X" << endl;}
};
class Y : public X {
public:
    Y() {cout << "Constructor Y" << endl;}
    ~Y() {cout << "Destructor Y" << endl;}
};

// Question 2
class Base {
public:
virtual void print() {
    cout << "Base" << endl;
}
};
class Derived : public Base {
public:
    void print() {
        cout << "Derived" << endl;
    }
};

int main() {
    Circle cir1;
    cir1.draw();
    
    Square sqr1;
    sqr1.draw();

    // Shape s1;
    // s1.draw();
    // Not Possible as Shape is an Abstract Class

    // Static Keyword in Function
    counter(); // Count: 1
    counter(); // Count: 2
    counter(); // Count: 3

    // Static Keyword in Class
    Example e1;
    Example e2;
    Example e3;    
    cout << e1.x++ << endl; // 0
    cout << e2.x++ << endl; // 1
    cout << e3.x++ << endl; // 2

    // Static Object
    int a = 0;
    if(a==0) {
        static Example e4;
    }
    cout << "Code ending.." << endl;

    // Friend Class & Function
    A a1;
    B b1;
    b1.showSecret(a1); // Friend Class
    revealSecret(a1);  // Friend Function

    // Ques 1
    Y obj;

    /* Output:
    Constructor X
    Constructor Y
    Destructor Y
    Destructor X */

    // Ques 2
    Base* b = new Derived();
    b->print();
    delete b;

    /*Output:
    Derived*/

    return 0;
}