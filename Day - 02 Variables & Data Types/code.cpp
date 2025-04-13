#include <iostream>
#include <iomanip> // for setprecision
#define PI 3.14 // Macro definition
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    cout<< "Value of PI: " << PI << endl;

    // Print Pattern
    cout<< "Pattern:\n";
    cout<< "****\n***\n**\n*\n";
    
    // Variables
    int a = 10;
    int b = 5;
    int c; // uninitialized variable
    cout<< "a = " << a << endl;
    cout<< "b = " << b << endl;
    cout<< "c = " << c << endl; // garbage value

    // Data Types
    cout<<"size of int = " <<sizeof(int)<< endl;
    cout<<"size of char = " <<sizeof(char)<< endl;
    cout<<"size of bool = " <<sizeof(bool)<< endl;
    cout<<"size of float = " <<sizeof(float)<< endl;
    cout<<"size of double = " <<sizeof(double)<< endl;

    int age = 25; // integer
    int marks = -200; // negative integer
    char grade = 'A'; // character
    bool isAdult = true; // boolean
    float pi = 3.14159265359; // floating point
    double pi2 = 3.14159265359; // double precision floating point

    cout<<age<<" "<<marks<<" "<<grade<<" "<<isAdult<<" "<< endl;
    cout<<setprecision(12)<<"Floating Point: "<<pi<< endl;
    cout<<setprecision(12)<<"Double Floating Point: "<<pi2<< endl;

    // Single Line Comment
    /* This is a
    Multi Line 
    Comment */

    // Input
    int x; // variable to store input (garbage value)
    cout<< "Enter a number: ";
    cin>>x;
    cout<< "You entered: "<<x<< endl;

    // Sum, Difference & Product of p and q
    int p;
    int q;
    cout<< "Enter p: ";
    cin>>p;
    cout<< "Enter q: ";
    cin>>q;
    int sum = p+q;
    int prod = p*q;
    int diff = p-q;
    cout<< "Sum of p and q: "<<sum<< endl;
    cout<< "Difference of p and q: "<<diff<< endl;
    cout<< "Product of p and q: "<<prod<< endl;

    // Print Average Marks
    float eng, math, sci;
    cout<< "Enter English marks: ";
    cin>>eng;
    cout<< "Enter Maths marks: ";
    cin>>math;
    cout<< "Enter Science marks: ";
    cin>>sci;
    float avg = (eng+math+sci)/3;
    cout<< "Average Marks: "<<avg<< endl;

    return 0;
}