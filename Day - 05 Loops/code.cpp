#include<iostream>
#include<cmath>
using namespace std;

int main () {
    // for Loop
    for (int i=1; i<=5; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    // Ques 1. Print "Hello, World!" 5 times
    for (int i=0; i<5; i++) {
        cout << "Hello, World!" << endl;
    }

    // Ques 2. Print numbers from 1 to n
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i=1; i<=n; i++) {
        cout << i << " ";
    }
    cout << endl;

    // Ques 3. Print sum of first N natural numbers
    int N, sum=0;
    cout << "Enter N: ";
    cin >> N;
    for (int i=1; i<=N; i++) {
        sum += i;
    }
    cout << "Sum = " << sum << endl;

    // while Loop
    int i = 1;  // initialization
    int m = 18;
    while (i <= m) {
        cout << i << " ";
        i++;    // updation
    }
    cout << endl;

    // Ques 1. Print square pattern using for loop
    for (int i=1; i<=4; i++) {
        cout << "****" << endl;
    }

    // Ques 2. Print numbers from m to 1 using for loop
    int p;
    cout << "Enter p: ";
    cin >> p;
    // First Method
    for (int i=p; i>=1; i--) {
        cout << i << " ";
    }
    cout << endl;
    // Second Method    
    for (int i=1; i<=p; i++) {
        cout << p-i+1 << " ";
    }
    cout << endl;

    // Ques 3. Print the sum of digits of a number using while loop
    int k, lastDigit, s=0;
    cout << "Enter no to calculate sum of its digits: ";
    cin >> k;
    while (k>0) {
        lastDigit = k%10;
        s += lastDigit;
        k /= 10;
    }
    cout << "Sum of digits = " << s << endl;

    // Ques 4. Print the sum of odd digits of a number using while loop
    int h, lastDig, digSum=0;
    cout << "Enter no to calculate sum of its odd digits: ";
    cin >> h;
    while (h>0) {
        lastDig = h%10;
        if (lastDig%2!=0) {
            digSum+= lastDig;
        }
        h /= 10;
    }
    cout << "Sum of digits = " << digSum << endl;

    // Ques 3. Print the digits of a number in reverse using while loop
    int l, last;
    cout << "Enter no to print digits in reverse: ";
    cin >> l;
    while (l>0) {
        last = l%10;
        cout << last;
        l /= 10;
    }
    cout << endl;

    // Ques 4. Reverse the given number and print the result
    int g, lastD, res=0;
    cout << "Enter no to calculate sum of its digits: ";
    cin >> g;
    while (g>0) {
        lastD = g%10;
        res = res*10 + lastD;
        g /= 10;
    }
    cout << "Reversed Number = " << res << endl;

    // do-while Loop
    int t = 1;
    do {
        cout << t << " ";
        t++;
    } while (t <= 5);
    cout << endl;

    int val = 1;
    // Gets done atleast once irrespective of condition
    do {
        cout << "Output of do-while Loop" << endl;
    } while (val > 5);

    // No output as condition donot satisfy
    while (val > 5) {
        cout << "Output of while Loop" << endl;
    }

    // break Statement
    int f = 1;
    while (f <= 10) {
        if (f == 3) {
            break;
        }
        cout << f << endl;
        f++;
    }
    cout << "Out of the loop" << endl;

    // WAP where user keep entering the numbers till they enter a multiple of 10
    int e;
    do {
        cout << "Enter the number: ";
        cin >> e;
        if (e%10==0) {
            break;
        }
        cout << "You entered " << e << endl;
    } while(true);

    // continue Statement
    for (int i=1; i<=10; i++) {
        if (i==4) {
            continue;
        }
        cout << i << endl;
    }

    // WAP to show numbers entered by the user except the multiples of 10
    int o;
    do {
        cout << "Enter the number: ";
        cin >> o;
        if (o%10==0) {
            continue;
        }
        cout << "You entered " << o << endl;
    } while(true);

    // Check if a number is prime or not
    int number;
    bool isPrime = true;
    cout << "Enter the number: ";
    cin >> number;
    for (int i=2; i<=n-1; i++){
        if (number%i==0){
            isPrime = false;
            break;
        }
    }
    if (isPrime) {
        cout << "Number is prime" << endl;
    } else {
        cout << "Number is not prime" << endl;
    }

    // Optimized Approach
    int numb;
    bool isPrime = true;
    cout << "Enter the number: ";
    cin >> numb;
    for (int i=2; i<=sqrt(numb); i++){
        if (numb%i==0){
            isPrime = false;
            break;
        }
    }
    if (isPrime) {
        cout << "Number is prime" << endl;
    } else {
        cout << "Number is not prime" << endl;
    }

    return 0; 
}