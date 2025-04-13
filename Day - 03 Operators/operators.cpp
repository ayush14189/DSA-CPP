#include<iostream>
using namespace std;

int main(){
    // Arithmetic Operators
    // Binary Operators
    int a = 10, b = 3;
    cout << "a: " << a << " b: " << b << endl;
    cout << "a + b: " << a + b << endl; // 13
    cout << "a - b: " << a - b << endl; // 7
    cout << "a * b: " << a * b << endl; // 30
    cout << "a / b: " << a / b << endl; // 3
    cout << "a % b: " << a % b << endl; // 1

    // Unary Operators
    int c = 3;
    cout << "c: " << c << endl; // 3
    // Post-Increment
    int d = c++;
    cout << "d = c++: " << d << endl; // 3
    cout << "c: " << c << endl; // 4
    // Pre-Increment
    int e = ++c;
    cout << "e = ++c: " << e << endl; // 5
    cout << "c: " << c << endl; // 5
    // Post-Decrement
    int f = c--;
    cout << "f = c--: " << f << endl; // 5
    cout << "c: " << c << endl; // 4
    // Pre-Decrement
    int g = --c;
    cout << "g = --c: " << g << endl; // 3
    cout << "c: " << c << endl; // 3
    
    // Assignment Operators
    int x = 10;
    cout<< "x: " << x << endl; // 10
    x += 5; // x = x + 5
    cout << "x += 5: " << x << endl; // 15
    x -= 5; // x = x - 5
    cout << "x -= 5: " << x << endl; // 10
    x *= 5; // x = x * 5
    cout << "x *= 5: " << x << endl; // 50
    x /= 5; // x = x / 5
    cout << "x /= 5: " << x << endl; // 10
    x %= 5; // x = x % 5
    cout << "x %= 5: " << x << endl; // 0

    // Relational Operators
    int m = 10, n = 20;
    cout << "m: " << m << " n: " << n << endl;
    cout << "m == n: " << (m == n) << endl; // 0
    cout << "m != n: " << (m != n) << endl; // 1
    cout << "m > n: " << (m > n) << endl; // 0
    cout << "m < n: " << (m < n) << endl; // 1
    cout << "m >= n: " << (m >= n) << endl; // 0
    cout << "m <= n: " << (m <= n) << endl; // 1 

    // Logical Operators
    cout << "((3>5) && (5<=7)): " << ((3>5) && (5<=7)) << endl; // 0
    cout << "((3>5) || (5<=7)): " << ((3>5) || (5<=7)) << endl; // 1
    cout << "!(3>5): " << !(3>5) << endl; // 1
    return 0;
}