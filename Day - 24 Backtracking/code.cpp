#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Backtracking in Array
void changeArr(int arr[], int n, int i) {
    if(i==n) { // Base Case
        printArr(arr, n);
        return;
    }
    arr[i] = i+1;
    changeArr(arr, n, i+1);
    arr[i] -= 2; // Backtracking 
}

// Find Subsets
void printSubsets(string str, string subset) {
    int n = str.size(); 
    if(n==0) { // Base Case
        cout << "\"" << subset << "\"" << endl;
        return;
    }
    char ch = str[0];
    printSubsets(str.substr(1, n-1), subset + ch); // Yes
    printSubsets(str.substr(1, n-1), subset); // No
}

// Find Permutations
void permutations(string str, string ans) {
    int n = str.size();
    if(n==0) { // Base Case
        cout << "\"" << ans << "\"" << endl;
        return;
    }
    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        permutations(str.substr(0, i) + str.substr(i+1, n-i-1), ans + ch);
    }
}

// N-Queens Problem
void printBoard(vector<vector<char>> board) {
    int n = board.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------" << endl;
}

bool isSafe(vector<vector<char>> board, int row, int col) {
    int n = board.size();

    // Horizontal
    for(int j=0; j<n; j++) {
        if(board[row][j] == 'Q') {
            return false;
        }
    }
    
    // Vertical
    for(int i=0; i<n; i++) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }

    // Diagonal Left
    for(int i=row, j=col; i>=0 && j>=0 ; i--, j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    // Diagonal Right
    for(int i=row, j=col; i>=0 && j<n; i--, j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    
    return true;
}

// Print all possible solutions
void nQueens1(vector<vector<char>> board, int row) {
    int n = board.size();
    if(row==n) { // Base Case
        printBoard(board);
        return;
    }
    for(int j=0; j<n; j++) { // Columns
        if(isSafe(board, row, j)) {
            board[row][j] = 'Q';
            nQueens1(board, row+1);
            board[row][j] = '.';  
        }      
    }
}

// Count all possible solutions
int nQueens2(vector<vector<char>> board, int row) {
    int n = board.size(), count = 0;
    if(row==n) { // Base Case
        printBoard(board);
        return 1;
    }
    for(int j=0; j<n; j++) { // Columns
        if(isSafe(board, row, j)) {
            board[row][j] = 'Q';
            count += nQueens2(board, row+1);
            board[row][j] = '.';  
        }      
    }
    return count; // No of possible solutions at each level
}

// Print any one solution
bool nQueens3(vector<vector<char>> &board, int row) {
    int n = board.size();
    if(row == n) { // Base Case
        printBoard(board);
        return true;
    }
    for(int j=0; j<n; j++) { // Columns
        if(isSafe(board, row, j)) {
            board[row][j] = 'Q';
            if(nQueens3(board, row+1)) {
                return true;
            }
            board[row][j] = '.';  
        }      
    }
    return false;
}

// Grid Ways
int ways1(int r, int c, int n, int m) {
    if(r == n-1 && c == m-1) { // Base Case for Destination
        return 1;
    }
    if(r >= n || c >= m) {
        return 0;
    }
    int v1 = ways1(r, c+1, n, m);
    int v2 = ways1(r+1, c, n, m);
    return v1 + v2;
}

int ways2(int r, int c, int n, int m, string ans) {
    if(r == n-1 && c == m-1) { // Base Case for Destination
        cout << ans << endl;
        return 1;
    }
    if(r >= n || c >= m) {
        return 0;
    }
    int v1 = ways2(r, c+1, n, m, ans + "R"); // Right
    int v2 = ways2(r+1, c, n, m, ans + "D"); // Down
    return v1 + v2;
}

// Sudoku Solver
void printSudoku(int sudoku[9][9]) {
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafeSudoku(int sudoku[9][9], int row, int col, int digit) {
    // Vertical
    for(int i=0; i<9; i++) {
        if(sudoku[i][col] == digit) {
            return false;
        }
    }
    // Horizontal
    for(int j=0; j<9; j++) {
        if(sudoku[row][j] == digit) {
            return false;
        }
    }
    // 3x3 Grid
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
    for(int i= startRow; i<=startRow+2; i++) {
        for(int j=startCol; j<=startCol+2; j++) {
            if(sudoku[i][j]==digit) {
            return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col) {
    if(row == 9) {
        // Sudoku Solved
        printSudoku(sudoku);
        return true;
    }
    int nextRow = row;
    int nextCol = col + 1;
    if(col+1==9){
        nextRow = row+1;
        nextCol = 0;
    }
    if(sudoku[row][col] != 0) {
        return  sudokuSolver(sudoku, nextRow, nextCol);
    }
    for(int digit=1; digit<=9; digit++) {
        if(isSafeSudoku(sudoku, row, col, digit)) {
            sudoku[row][col] = digit;
            if(sudokuSolver(sudoku, nextRow, nextCol)) {
                return true;
            } 
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main() {
    // Backtracking in an Array
    int arr[5] = {0};

    // Find Subsets
    string str = "abc";
    string subset = "";
    cout << "Subsets:"  << endl;
    printSubsets(str, subset);

    // Find Permutations
    string ans = "";
    cout << "Permuations:" << endl;
    permutations(str, ans);

    // N-Queens Problem
    cout << "N-Queens Problem:" << endl;
    vector<vector<char>> board;
    int n = 4;
    for(int i=0; i<n; i++) {
        vector<char> newRow;
        for(int j=0; j<n; j++) {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    printBoard(board);
    // Print all possible solutions
    nQueens1(board, 0); 
    // Count all possible solutions
    int count = nQueens2(board,0);
    cout << "Count: " << count << endl;
    cout << "--------" << endl;
    // Print any one solution
    nQueens3(board, 0); 

    // Grid Ways
    int n1 = 3, m1 = 3;
    cout << "Grid Ways: " << ways1(0, 0, n1, m1) << endl;
    string answer = "";
    cout << "Grid Ways: " << ways2(0, 0, n1, m1, answer) << endl;

    // Sudoku Solver
    int sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                        {4, 9, 0, 1, 5, 7, 0, 0, 2},
                        {0, 0, 3, 0, 0, 4, 1, 9, 0},
                        {1, 8, 5, 0, 6, 0, 0, 2, 0},
                        {0, 0, 0, 0, 2, 0, 0, 6, 0},
                        {9, 6, 0, 4, 0, 5, 3, 0, 0},
                        {0, 3, 0, 0, 7, 2, 0, 0, 4},
                        {0, 4, 9, 0, 3, 0, 0, 5, 7},
                        {8, 2, 7, 0, 0, 9, 0, 1, 3}};
    sudokuSolver(sudoku, 0, 0);

    return 0;
}