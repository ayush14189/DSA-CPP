#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Dynamic Memory Allocation
void funcInt() {
    int *ptr = new int;
    *ptr = 5;
    cout << *ptr << endl;
    delete ptr;
}

void funcArr() {
    cout << "Enter the size: ";
    int size;
    cin >> size;

    int *ptr = new int[size];
    int x = 1;
    for(int i=0; i<size; i++) {
        ptr[i] = x;
        cout << ptr[i] << " ";
        x++;
    }
    cout << endl;
    delete [] ptr;
}

// Memory Leak
int* func() {
    int *ptr = new int;
    *ptr = 1200;
    cout << "ptr points to " << *ptr << endl;
    return ptr;
}

// Pair Sum
vector<int> pairSum(vector<int> arr, int target) {
    int st = 0, end = arr.size()-1;
    int currSum = 0;
    vector<int> ans;

    while(st < end) {
        currSum = arr[st] + arr[end];
        if (currSum == target) {
            ans.push_back(st);
            ans.push_back(end);
            return ans;  
        } else if(currSum > target) {
            end--;
        } else {
            st++;
        }
    }
    return ans;
}

int main() {
    // 1D Dynmaic Array
    cout << "Enter the size: ";
    int size;
    cin >> size;

    int *arr = new int[size];
    int x = 1;
    for(int i=0; i<size; i++) {
        arr[i] = x;
        cout << arr[i] << " ";
        x++;
    }
    cout << endl;

    // Dynamic Memory Allocation
    funcArr();
    funcInt();

    // Memory Leak
    int *y = func();
    cout << "ptr in main() function points to " << *y << endl;
    // Heap memory isn't freed yet

    // 2D Dynamic Arrays
    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter cols: ";
    cin >> cols;

    int **matrix = new int*[rows];
    for(int i=0; i<rows; i++) {
        matrix[i] = new int[cols];
    }

    int z = 1;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] = z++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Vectors
    vector<int> vec1;
    cout << vec1.size() << endl;
    vector<int> vec2 = {1, 2, 3, 4};
    cout << vec2.size() << endl;
    vector<int> vec3(5, -1);
    for(int i=0; i<vec3.size(); i++) {
        cout << vec3[i] << " ";
    }
    cout << endl;

    // Vector Implementation in Memory
    vector<int> vec = {1, 2, 3, 4};
    cout << "Size: " << vec.size() << endl;         // 4
    cout << "Capacity: " << vec.capacity() << endl; // 4

    vec.push_back(5); // To add a value at the end of vector
    cout << "Size: " << vec.size() << endl;         // 5
    cout << "Capacity: " << vec.capacity() << endl; // 8

    vec.pop_back();  // To remove a value from the end of vector
    cout << "Size: " << vec.size() << endl;         // 4
    cout << "Capacity: " << vec.capacity() << endl; // 5  

    // Pair Sum
    vector<int> v = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = pairSum(v, target);
    cout << ans[0] << "," << ans[1] << endl;
    
    // 2D Vectors
    vector<vector<int>> m = {{1, 2, 3}, {4, 5}, {6}};
    for(int i=0; i<m.size(); i++) {
        for(int j=0; j<m[i].size(); j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    // Ques - Predict the Output
    vector<int> v1;
    for(int i=0; i<5; i++) {
        v1.push_back(i);
    }
    cout << v1.size() << endl;     // 5
    cout << v1.capacity() << endl; // 8

    return 0;
}