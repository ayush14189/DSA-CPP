#include<iostream>
using namespace std;

int main() {
    // if-else statement
    int age;
    cout<<"Enter your age: ";
    cin>>age;
    
    if (age>=18) {
        cout << "You are eligible to vote" << endl;
    } 
    // if (age>=35) {
    //     cout << "You are eligible to become a president" << endl;
    // } 
    else {
        cout << "You are not eligible to vote" << endl;
    }

    // Ques 1. Print the largest of 2 numbers.
    int a, b;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    if (a>b) {
        cout << "a is greater than b" << endl;
    } else {
        cout << "b is greater than a" << endl;
    }

    // Ques 2. Print if a number is Odd or Even.
    int num;
    cout << "Enter the number: ";
    cin >> num;
    if (num%2==0) {
        cout << "Number is Even" << endl;
    } else {
        cout << "Number is Odd" << endl;
    }

    // else if statement
    int marks;
    cout << "Enter the marks: ";
    cin >> marks;
    if (marks >= 90) {
        cout << "A" << endl;
    } else if (marks >= 80 && marks <= 90) {
        cout << "B" << endl;
    } else if (marks >= 70 && marks <= 80) {
        cout << "C" << endl;
    } else if (marks >= 60 && marks <= 70) {
        cout << "D" << endl;
    } else {
        cout << "Fail" << endl;
    }

    // Ques 1. Create an Income Tax Calculator
    int income;
    float tax;
    cout << "Enter income (in Lakhs): ";
    cin >> income;
    if (income < 5) {
        tax = 0;
    } else if (income <= 10) {
        tax = 0.2*income;
    } else {
        tax = 0.3*income;
    }
    cout << "Tax = " << (tax*100000) << endl;

    // Ques 2. Print the largest of 3 numbers
    int x, y, z;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << "Enter z: ";
    cin >> z;
    if (x>=y && x>=z) {
        cout << "x is the largest number" << endl;
    } else if (y>=z) {
        cout << "y is the largest number" << endl;
    } else {
        cout << "z is the largest number" << endl;
    }

    // Ternary Operator
    // Example 1 - If adult or not
    bool isAdult;
    int Age = 34;
    isAdult = Age >= 18 ? true : false;

    // Example 2 - Largest of 2 numbers
    int A = 10, B = 5;
    int largest = (A >= B) ? A : B;
    cout << "Largest is: " << largest << endl;

    // Example 3 - Odd/Even
    int n = 13;
    bool isEven = num%2==0 ? true : false;

    // Switch Statement
    int day;
    cout << "Enter the day number: ";
    cin >> day;
    switch(day) {
        case 1: cout << "Monday" << endl;
                break;
        case 2: cout << "Tuesday" << endl;
                break;
        case 3: cout << "Wednesday" << endl;
                break;
        case 4: cout << "Thursday" << endl;
                break;
        case 5: cout << "Friday" << endl;
                break;
        case 6: cout << "Saturday" << endl;
                break;
        case 7: cout << "Sunday" << endl;
                break;
        default : cout << "Invalid Day" << endl;
    }

    // Build a Calculator using switch for 4 basic operations (+,-,*,/)
    int i, j;
    char op;
    cout << "Enter i: ";
    cin >> i;
    cout << "Enter j: ";
    cin >> j;     
    cout << "Enter the operator: ";
    cin >> op; 
    switch(op) {
        case '+': cout << "i + j = " << (i+j) << endl;
                break;
        case '-': cout << "i - j = " << (i-j) << endl;
                break;
        case '*': cout << "i * j = " << (i*j) << endl;
                break;
        case '/': cout << "i / j = " << (i/j) << endl;
                break;
        default: cout << "Invalid Operator" << endl;
    }

    return 0;
}