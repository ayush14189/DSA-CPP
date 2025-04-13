#include<iostream>
#include <algorithm>
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printChar(char arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble Sort
void bubbleSort(int *arr, int n) {
    bool isSwap = false;
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap) {
            // Array is already sorted - O(1)
            return;
        }
    }
    printArr(arr, n);
}

// Selection Sort
void selectionSort(int *arr, int n) {
    for(int i=0; i<n-1; i++) {
        int minIdx = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    printArr(arr, n);
}

// Insertion Sort
void insertionSort(int *arr, int n) {
    for(int i=1; i<n; i++) {
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] > curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
    printArr(arr, n);
}

// Counting Sort
void countSort(int *arr, int n) {
    int freq[100000]; // range
    int minVal = INT16_MAX, maxVal = INT16_MIN;

    // 1st Step - O(n)
    for(int i=0; i<n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
        freq[arr[i]]++;
    }
    // 2nd Step - O(range) = O(max - min)
    for(int i=minVal, j=0; i<=maxVal; i++) {
        while(freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
        }
    }
    printArr(arr, n);
}

// Sort the character array using Insertion Sort in descending order
void sortChar(char *arr, int n) {
        for(int i=1; i<n; i++) {
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] < curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
    printChar(arr, n);
}

int main() {
    int arr[] = {5, 4, 1, 3, 2};
    int n = sizeof(arr)/sizeof(int);
    printArr(arr, n);
    bubbleSort(arr, n);
    selectionSort(arr, n);
    insertionSort(arr, n);

    int arr2[] = {1, 4, 1, 3, 2, 4, 3, 7};
    int m =sizeof(arr2)/sizeof(int);
    printArr(arr2, m);
    countSort(arr2, m);

    // Inbuilt Sort in C++
    int a[8] = {1, 4, 1, 3, 2, 4, 3, 7};
    // Ascending Order
    sort(a+2, a+5);
    printArr(a, 8);
    // Descending Order
    sort(a, a+8, greater<int>());
    printArr(a, 8);

    // Sort the character array using Insertion Sort in descending order
    char ch[] = {'f', 'b', 'a', 'e', 'c', 'd'};
    int k = sizeof(ch)/sizeof(char);
    sortChar(ch, k);

    return 0;
}