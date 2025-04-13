#include<iostream>
using namespace std;

void changeA(int a) {
    a = 20;
    cout << "Changed Value (Pass by Value) = " << a << endl;
}

void changeB(int *ptr) {
    *ptr = 20;
    cout << "Changed Value (Pass by Reference) = " << *ptr << endl;
}

void changeC(int &c) {
    c = 50;
    cout << "Changed Value (Pass by Reference) = " << c << endl;
}

int main() {
    int a = 10;
    int *ptr = &a;
    float pi = 3.14;
    float *ptr2 = &pi;
    int **pptr = &ptr;

    cout << &a << " = " << ptr << endl;
    cout << &pi << " = " << ptr2 << endl;
    cout << &ptr << " = " << pptr << endl;
    cout << "Size of int pointer = " << sizeof(ptr) << endl;
    cout << "Size of float pointer = " << sizeof(ptr2) << endl;

    // Dereference Operator
    cout << "*ptr = *(&a) = " << *ptr << endl; // *ptr = *(&a) = 10
    *ptr = 20;
    cout << "New value of a = " << a << endl;
  
    // NULL Pointer
    int *p = NULL;
    cout << p << endl;
    // cout << *p << endl; // Segementation Fault

    // Passing Arguments
    // Pass by Value
    int x = 10;
    changeA(x);
    cout << "x = " << x << endl; // 10
    // Pass by Reference using Pointer
    int y = 10;
    changeB(&y);
    cout << "y = " << y << endl; // 20
    // Pass by Reference using Reference Variable
    int s = 10;
    int &t = s;
    t = 25;
    cout << "s = " << s << endl;
    cout << "t = " << t << endl;
    changeC(s);
    cout << "s = " << s << endl;

    // Practice Question
    int i = 5, j = 10;
    int *pt1 = &i, *pt2 = &j;
    pt2 = pt1;
    cout << pt2 << endl;
    cout << pt1 << endl;
    cout << &i << endl;

    return 0;
}