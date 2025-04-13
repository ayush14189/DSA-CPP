#include<iostream>
using namespace std;

void sayHello() {
    cout << "Hello :)\n";
}

void assistant() {
    sayHello();             // Function Call
    cout << "Work Done!\n";
}

void helloWorld();          // Function Declaration

int sum(int a, int b){      // a,b are parameters
    int sum = a + b;
    return sum;
}

double sum(double a, double b) {
    return a + b;
}

int sum(int a, int b, int c) {
    return a + b + c;
}

int diff(int a, int b=1) {  // b=1 is default parameter
    int diff = a - b;       // diff is local scope
    return diff;
}

// WAF to find the product of 2 numbers - a & b
int prod(int a, int b) {
    return a * b;
}

// WAF to print if a number is odd or even
bool isEven(int n) {
    if(n%2==0) {
        return true;
    } else {
        return false;
    }
}

// WAF to print factorial of number n
int factorial(int n) {
    int fact = 1;
    for(int i=1; i<=n; i++) {
        fact *= i;
    }
    return fact;
}

// WAF to find if a number is prime or not
bool isPrime(int n) {
    if(n==1) {          // 1 is Non-Prime
        return false;
    }
    for(int i=2; i<=n-1; i++) {
        if(n%i==0) {    // Non-Prime
            return false;
        }
    }
    return true;        // Prime
}

bool isPrime2(int n) {
    if(n==1) {          // 1 is Non-Prime
        return false;
    }
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {    // Non-Prime
            return false;
        }
    }
    return true;        // Prime
}

// WAF to find the Binary Coefficient for given n & r
int binCoeff(int n, int r) {
    int val1 = factorial(n);
    int val2 = factorial(r);
    int val3 = factorial(n-r);
    int result = val1/(val2*val3);
    return result;
} 

// WAF to print all prime numbers in range from 2 to n
int allPrimes(int n) {
    for(int i=2; i<=n; i++) {
        if(isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
} 

int main() {
    assistant();
    helloWorld();

    int s = sum(2,6);           // 2,6 are arguments
    cout << "Sum = " << s << endl;
    
    // Function Overloading
    double x = sum(2.45,6.23);
    cout << "Sum = " << x << endl;
    int y = sum(2,3,4);
    cout << "Sum = " << y << endl;

    int d = diff(4);
    cout << "Difference = " << d << endl;

    cout << prod(2,5) << endl;

    cout << isEven(4) << endl;
    cout << isEven(19) << endl;

    factorial(0);
    factorial(1);
    factorial(2);
    factorial(3);
    factorial(4);
    factorial(5);

    cout << isPrime(12) << endl;    // 0
    cout << isPrime(19) << endl;    // 1
    cout << isPrime2(12) << endl;    // 0
    cout << isPrime2(19) << endl;    // 1

    cout << binCoeff(4,2) << endl;
    cout << binCoeff(5,3) << endl;

    allPrimes(50);
    
    return 0;
}

void helloWorld() {
    cout << "Hello, World!" << endl; // Function Definition
}