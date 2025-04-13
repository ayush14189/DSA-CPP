#include<iostream>
using namespace std;

void binToDec (int binNum) {
    int n = binNum;
    int decNum = 0;
    int pow = 1; // 2^0, 2^1, 2^2,..
    while(n>0) {
        int lastDigit = n%10;
        decNum += lastDigit * pow;
        pow *= 2;
        n = n/10;
     }
    cout << "Decimal of " << binNum << " = " << decNum << endl;
}

void decToBin (int decNum) {
    int n = decNum;
    int binNum = 0;
    int pow = 1; // 10^0, 10^1, 10^2,..
    while(n>0) {
        int rem = n % 2;
        binNum += rem * pow;
        n = n/2;
        pow *= 10;
    }
    cout << "Binary of " << decNum << " = " << binNum << endl;
}

int main(){

    // Data Type Modifiers
    long long a = 15;
    unsigned short int age = 25;            // Multiple modifiers
    cout << sizeof(int) << endl;            // 4
    cout << sizeof(long int) << endl;       // 4 (based on this System)
    cout << sizeof(double) << endl;         // 8
    cout << sizeof(long double) << endl;    // 12 (based on this System)
    cout << sizeof(short int) << endl;      // 2
    cout << sizeof(long long int) << endl;  // 8

    binToDec(100101);
    decToBin(5);

    return 0;
}