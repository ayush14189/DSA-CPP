#include <iostream>
using namespace std;

// Check Odd or Even
void oddOrEven(int num) {
    if(!(num & 1)) {
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl; 
    }
}

// Get ith Bit
int getIthBit(int num, int i) {
    int bitMask = 1 << i;
    if(!(num & bitMask)) {
        return 0;
    } else {
        return 1;
    }
}

// Set ith Bit
int setIthBit(int num, int i) {
    int bitMask = 1 << i;
    return (num | bitMask); 
}

// Clear ith Bit
int clearIthBit(int num, int i) {
    int bitMask = ~(1 << i);
    return (num & bitMask); 
}

// Check for power of 2
bool isPowerOf2(int num) {
    if(!(num & (num-1))) {
        return true;
    }
    return false;
}
/* Ques - Update ith Bit in a number to given value (0 or 1)
num = 7, i = 2, val = 0
num = 7, i = 3, val = 1 */

int updateIthBit(int num, int i, int val) {
    num = num & ~(1 << i);  // Clear ith bit
    num = num | (val << i); // Set ith bit
    return num;
}

int updateIthBit2(int num, int i, int val) {
    if(val == 1){   // Set ith bit
        int bitMask = 1 << i;
        return (num | bitMask);
    } else {        // Clear ith bit
        int bitMask = ~(1 << i);
        return (num & bitMask);
    }
}

// Clear last i Bits
int clearLastIBits(int num, int i){
    int bitMask = (~0) << i;
    return (num & bitMask);
}

// Count Set Bits
int countSetBits(int num) {
    int count = 0;
    while(num > 0) {
        int lastDigit = (num & 1);
        count += lastDigit;
        num = num >> 1;
    }
    return count;
}

// Fast Exponentiation 
int fastExpo(int x, int n) {
    int ans = 1;
    while(n>0) {
        int lastBit = (n & 1);
        if(lastBit) {
            ans = ans * x;
        }
        x = x * x;
        n = n >> 1;
    }
    return ans;
}

int main() {
    // Bitwise Operators
    cout << (3 & 5) << endl; // 1 - Bitwise AND
    cout << (3 | 5) << endl; // 7 - Bitwise OR
    cout << (3 ^ 5) << endl; // 6 - Bitwise XOR
    
    // One's Complement
    cout << (~6) << endl;   // -7
    cout << (~0) << endl;   // -1

    // Binary Shift Operators
    cout << (7 << 2) << endl;   // 28 - Left Shift
    cout << (7 >> 2) << endl;   // 1 - Right Shift

    // Practice Questions
    cout << (~4) << endl;       // -5
    cout << (8 >> 1) << endl;   // 4

    // Check if Odd or Even
    oddOrEven(6);
    oddOrEven(5);

    // Get ith Bit
    cout << getIthBit(6, 2) << endl; // 1
    cout << getIthBit(7, 5) << endl; // 0

    // Set ith Bit
    cout << setIthBit(6, 3) << endl; // 14
    cout << setIthBit(7, 5) << endl; // 39 

    // Clear ith Bit
    cout << clearIthBit(6, 1) << endl; // 4
    cout << clearIthBit(7, 5) << endl; // 7

    // Check for Power of 2
    cout << isPowerOf2(16) << endl; // 1 - true
    cout << isPowerOf2(26) << endl; // 0 - false

    // Update ith Bit according to given value
    cout << updateIthBit(8, 2, 1) << endl;
    cout << updateIthBit2(8, 2, 1) << endl;

    // Clear Last i Bits
    cout << clearLastIBits(15, 2) << endl; // 12
    cout << clearLastIBits(6, 2) << endl; // 4

    // Count Set Bits
    cout << countSetBits(10) << endl; // 2
    cout << countSetBits(7) << endl; // 3

    // Fast Exponentiation
    cout << fastExpo(3, 4) << endl; // 81
    cout << fastExpo(3, 5) << endl; // 243 

    return 0;
}