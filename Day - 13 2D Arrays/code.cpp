#include<iostream>
using namespace std;

void spiralMatrix(int matrix[][4], int n, int m) {
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;

    while(srow<=erow && scol<=ecol) {
        // top
        for(int j=scol; j<=ecol; j++) {
            cout << matrix[srow][j] << " ";
        }
        // right
        for(int i=srow+1; i<=erow; i++) {
            cout << matrix[i][ecol] << " ";
        }
        // bottom
        for(int j=ecol-1; j>=scol; j--) {
            if(srow == erow) {  // Middle Row aready covered in Top
                break;
            }
            cout << matrix[erow][j] << " ";
        }
        // left
        for(int i=erow-1; i>=srow+1; i--) {
            cout << matrix[i][scol] << " ";
        }
        srow++; scol++;
        erow--; ecol--;
    }
    cout << endl;
}

// Diagonal Sum - O(N^2)
int diagonalSum(int mat[][4], int n) {
    int sum = 0;
    for(int i=0; i<n;i++) {
        for(int j=0; j<n; j++) {
            if(i==j) {
                sum+=mat[i][j];
            } else if(j==n-i-1) {
                sum+=mat[i][j];
            }

        }
    }
    cout << "Diagonal Sum = " << sum << endl;
    return sum;
}

// Diagonal Sum (Optimized) - O(N)
int diagonalSum2(int mat[][4], int n) {
    int sum = 0;
    for(int i=0; i<n;i++) {
        sum+=mat[i][i];         // Primary Diagonal
        if(i != n-i-1){
            sum+=mat[i][n-i-1]; // Secondary Diagonal
        }
    }
    cout << "Diagonal Sum = " << sum << endl;
    return sum;
}

// Search in Sorted Matrix
bool search(int mat[][4], int n, int m, int key) {
    int i=0, j=m-1;
    while(i<n && j>=0) {
        if(mat[i][j] == key) {
            cout << "Found at Cell ("<< i << "," << j << ")" << endl;
            return true;
        } else if(mat[i][j] > key) {
            // Left
            j--;
        } else {
            // Down
            i++;
        }
    }
    cout << "Key not found!" << endl;
    return false;
}

// 
void func1(int mat[][4], int n, int m) {
    cout << "0th row ptr: " << mat << endl;
    cout << "1st row ptr: " << mat + 1 << endl;
    cout << "2nd row ptr: " << mat + 2 << endl;
    cout << "3rd row ptr: " << mat + 3 << endl;

    cout << "0th row value: " << *mat << endl;
    cout << "1st row value: " << *(mat + 1) << endl;
    cout << "2nd row value: " << *(mat + 2) << endl;
    cout << "3rd row value: " << *(mat + 3) << endl;

    cout << *(*(mat + 2) + 3) << endl; // mat[2][3]
} 

void func2(int (*mat)[4], int n, int m) {
    cout << "1st row ptr: " << mat << endl;
    cout << "2nd row ptr: " << mat + 1 << endl;
    cout << "3rd row ptr: " << mat + 2 << endl;
    cout << "4th row ptr: " << mat + 3 << endl;
} 

int main() {
    // 2D Arrays
    int student[3][3] = {{100, 100, 100},
                        {85, 74, 90},
                        {75, 80, 85}};
    cout << student[2][1] << endl; // 80

    // Input & Output 2D Array
    int n;
    cout << "Enter no of rows: ";
    cin >> n;
    int m;
    cout << "Enter no of columns: ";
    cin >> m;
    int arr[n][m];
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++){     // Input
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<n; i++){     // Output
        for(int j=0; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Spiral Matrix
    int a[4][4] = {{1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}};
    spiralMatrix(a, 4, 4);

    int a2[3][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12}};
    spiralMatrix(a2, 3, 4);

    // Diagonal Sum
    diagonalSum(a, 4); // 64
    diagonalSum2(a, 4); // 64
    // int b[3][3] = {{1, 2, 3},
    //                 {4, 5, 6},
    //                 {7, 8, 9}};
    // diagonalSum(b, 3); // 25

    // Search in Sorted Matrix
    int matrix[4][4] = {{10, 20, 30, 40},
                        {15, 25, 35, 45},
                        {27, 29, 37, 48},
                        {32, 33, 39, 50}};
    search(matrix, 4, 4, 33);

    // Matrix Pointers
    cout << a << " = " << &a[0][0] << endl;
    cout << a + 1 << " != " << &a[0][1] << endl;    
    cout << a + 1 << " = " << &a[1][0] << endl;
    func1(a, 4, 4);
    func2(a, 4, 4);   

    return 0;
}