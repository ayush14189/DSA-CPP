#include <iostream>
#include <vector>
using namespace std;

// Factorial using recursion
int factorial(int n) {
    if(n==0) { // Base Case
        return 1;
    }
    return n * factorial(n-1);
}

// Print numbers from n to 1 using recursion
void print(int n) {
    if(n==0) { // Base Case
        return;
    }
    cout << n << " ";
    print(n-1);
}

// Stack Overflow (Infinite Recursion)
void func() {
    cout << "Function called" << endl;
    func();
}

// Sum of N Natural Numbers
int sum(int n) {
    if(n==1) { // Base Case
        return 1;
    }
    return n + sum(n-1);
}

// Print Nth Fibonacci Numbers
int fibonacci(int n) {
    if(n==0 || n==1) { // Base Case
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

// Check if Array is sorted
bool isSorted(int arr[ ], int n, int i) {
    if(i==n-1) { // Base Case
        return true;
    }
    if(arr[i] > arr[i+1]) {
        return false;
    }
    return isSorted(arr, n, i+1);
}

// First Occurrence of element in vector
int firstOccurrence(vector<int> arr, int i, int target) {
    if(i == arr.size()) { // Base Case
        return -1;
    }
    if(arr[i]==target) {
        return i;
    }
    return firstOccurrence(arr, i+1, target);
}

// Last Occurrence of element in vector
int lastOccurrence(vector<int> arr, int i, int target) {
    if(i == arr.size()) { // Base Case
        return -1;
    }
    int idx = lastOccurrence(arr, i+1, target);
    if(idx == -1 && arr[i] == target) {
        return i;
    }
    return idx;
}

// Print X to the power of N
int pow(int x, int n) {
    if(n==0) { // Base Case
        return 1;
    }
    int halfPow = pow(x, n/2);
    int halfPowSquare = halfPow * halfPow;
    if(n%2!=0) {
        return halfPowSquare * x;
    }
    return halfPowSquare;
}

int main() {

    // Factorial using recursion
    int ans = factorial(5);
    cout << ans << endl; // 120

    // Print numbers from n to 1 using recursion
    print(5);
    cout << endl;

    // Stack Overflow (Infinite Recursion)
    // func(); // Stops with Segmentation Fault

    // Sum of N Natural Numbers
    cout << sum(5) << endl;

    // Print Nth Fibonacci Numbers
    cout << fibonacci(0) << " ";
    cout << fibonacci(1) << " ";
    cout << fibonacci(2) << " ";
    cout << fibonacci(3) << " ";
    cout << fibonacci(4) << " ";
    cout << fibonacci(5) << " ";
    cout << fibonacci(6) << endl;

    // Check if Array is sorted
    int arr1[] = {1, 2, 3, 4, 5}; 
    int arr2[] = {1, 2, 4, 3, 5}; 
    cout << isSorted(arr1, 5, 0) << endl; // sorted: 1
    cout << isSorted(arr2, 5, 0) << endl; // unsorted: 0

    // First Occurrence of element in vector
    vector<int> v1 = {1, 2, 3, 3, 3, 4};
    cout << firstOccurrence(v1, 0, 3) << endl; // 2
    cout << firstOccurrence(v1, 0, 4) << endl; // 5
    cout << firstOccurrence(v1, 0, 9) << endl; // -1
    
    // Last Occurence of element in vector 
    cout << lastOccurrence(v1, 0, 3) << endl; // 4
    cout << lastOccurrence(v1, 0, 7) << endl; // -1

    // Print X to the power of N
    cout << pow(2, 5) << endl; // 32
    cout << pow(2, 4) << endl; // 16

    return 0;
}