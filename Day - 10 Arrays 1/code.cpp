#include<iostream>
using namespace std;

void func(int arr[]) {
    arr[0] = 1000;
}

void func2(int *ptr) {
    ptr[0] = 1000;
}

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArr2(int *ptr, int n) {
    for(int i=0; i<n; i++) {
        cout << *(ptr + i) << endl;
    }
}

// Linear Search
int linearSearch(int *arr, int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binSearch(int *arr, int n, int key) {
    int start = 0, end = n-1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(arr[mid] == key) {
            return mid;         // Key Found
        } else if(arr[mid] < key) {
            start = mid + 1;    // 2nd Half
        } else {
            end = mid - 1;      // 1st Half
        }
    }
    return -1;
}

int main() {
    int marks[50]; // 0 to 49
    cout << marks[0] << endl; // Garbage Values
    cout << marks[1] << endl;
    cout << marks[2] << endl;
    cout << marks[3] << endl;

    int age[50] = {1, 2, 3};
    cout << age[0] << endl;
    cout << age[1] << endl;
    cout << age[2] << endl;
    cout << age[3] << endl; // Initialized to 0 (for rest)

    int b[] = {23, 34, 55}; // Length = 3

    int length = sizeof(marks)/sizeof(int); // Length of array
    cout << length << endl;

    // Input and Output an Array
    int n;
    cout << "Enter length of the array: ";
    cin >> n;
    int arr[n];
    // int n = sizeof(arr)/sizeof(int);
    // Input an Array
    cout << "Enter the values of array: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    // Output an Array
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Find largest and smallest in an array
    int array[] = {5, 4, 3, 9, 12};
    int len = sizeof(array)/sizeof(int);
    int max = array[0];
    int min = array[0];
    for(int i=0; i<len; i++) {
        if(max < array[i]) {
            max = array[i];
        }
        if(min > array[i]) {
            min = array[i]; 
        }
    }
    cout << "Largest in array = " << max << endl;
    cout << "Smallest in array = " << min << endl;

    // Arrays are passed by Reference
    int x[] = {1, 2, 3, 4, 5};
    int l = sizeof(x)/sizeof(int);
    cout << *x << endl;     // x[0] = 1
    cout << *(x+1) << endl; // x[1] = 2   
    cout << *(x+2) << endl; // x[2] = 3   
    
    int y[] = {1, 2, 3, 4, 5};
    func(y); // Passing array name is equivalent to passing the pointer
    cout << y[0] << endl;
    func2(y);
    cout << y[0] << endl;

    printArr(x, l); // Length of the array must also be passed to the function

    // Linear Search & Binary Search
    int p[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int m = sizeof(p)/sizeof(int);
    cout << "The key using linear search is at index: " << linearSearch(p, m, 10) << endl;
    cout << "The key using binary search is at index: " << binSearch(p, m, 10) << endl;

    // Reverse an Array
    int q[] = {5, 4, 3, 9, 2};
    int o = sizeof(q)/sizeof(int);
    // With Extra Space
    int copyArray[o];
    for(int i=0; i<o; i++) {
        int j = n-i-1;
        copyArray[i] = q[j];
    }
    for(int i=0; i<o; i++) {
        q[i] = copyArray[i];
    }
    printArr(q, o);

    // Without Extra Space - 2 Pointer Approach
    int start = 0, end = o-1;
    while(start < end) {
        // Swap
        // int temp = q[start];
        // q[start] = q[end];
        // q[end] = temp;
        swap(q[start], q[end]);
        start++;
        end--;
    }
    printArr(q, o);

    // Pointer Arithmetic
    // Increment & Decrement Operators
    int z = 10;
    int *zptr = &z;
    cout << zptr << endl;
    zptr++; // Shift by 4 bytes
    cout << zptr << endl;

    char e = 'a';
    char *eptr = &e;
    eptr++; // Shift by 1 byte

    int k = 3;
    int *kptr = &k;
    // 1st value == 3rd value
    cout << kptr << endl; // 1st value
    kptr++;
    cout << kptr << endl;
    kptr--;
    cout << kptr << endl; // 3rd value

    // Addition & Subtraction of Constants
    cout << (kptr + 3) << endl;
    cout << (kptr - 3) << endl;
    int g[] = {2, 5, 1, 7, 9};
    int s = sizeof(g)/sizeof(int);
    cout << g << endl;
    cout << g+1 << endl;
    cout << g+2 << endl;
    cout << g+3 << endl;
    printArr2(g, s);

    // Addition & Subtraction of Constants
    int h = 10;
    int *hptr1 = &h;
    int *hptr2 = hptr1 + 3;
    cout << "hptr1 = " << hptr1 << endl;
    cout << "hptr2 = " << hptr2 << endl;
    cout << "hptr2 - hptr1 = " << hptr2 - hptr1 << endl;

    int f[20] = {1, 2, 3, 4, 5};
    int *fptr1 = f;
    int *fptr2 = fptr1 + 3;
    cout << "Value stored at fptr1 = " << *fptr1 << endl;
    cout << "Value stored at fptr2 = " << *fptr2 << endl;
    cout << "No of spaces between = " << (fptr2 - fptr1) << endl;

    // Comparison of two Pointers
    cout << (fptr1 > fptr2) << endl;    // 0
    cout << (fptr1 >= fptr2) << endl;   // 0
    cout << (fptr1 < fptr2) << endl;    // 1
    cout << (fptr1 <= fptr2) << endl;   // 1
    cout << (fptr1 == fptr2) << endl;   // 0
    cout << (fptr1 != fptr2) << endl;   // 1

    return 0;
}