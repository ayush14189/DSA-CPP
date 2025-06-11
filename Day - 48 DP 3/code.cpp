#include <iostream>
#include <vector>
using namespace std;

// Coin Change - Leetcode 512 
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(amount+1, 0));

    for(int i=0; i<n+1; i++) {
        dp[i][0] = 1;
    }

    for (int i=1; i<n+1; i++) {
        for(int j=1; j<amount+1; j++) {
            if(coins[i-1] <= j) { // Valid
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]; 
            } else { // Invalid
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amount]; 
}

// Rod Cutting Problem
int rodCutting(vector<int> price, vector<int> length, int rodLength) {
    int n = length.size();

    vector<vector<int>> dp(n+1, vector<int>(rodLength+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<rodLength+1; j++) {
            if(length[i-1] <= j) {
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][rodLength];
}

// Longest Common Subsequence (Recursion)
int lcsRec(string str1, string str2) {
    if(str1.size() == 0 || str2.size() == 0) {
        return 0;
    }
    
    int n = str1.size();
    int m = str2.size();

    if(str1[n-1] == str2[m-1]) {
        return 1 + lcsRec(str1.substr(0, n-1), str2.substr(0, m-1));
    } else {
        int ans1 = lcsRec(str1.substr(0, n-1), str2);
        int ans2 =  lcsRec(str1, str2.substr(0, m-1));
        return max(ans1, ans2);
    }
}

// Longest Common Subsequence (Memoization) - O(n*m)
int lcsMem(string str1, string str2, vector<vector<int>> dp) {
    if(str1.size() == 0 || str2.size() == 0) {
        return 0;
    }

    int n = str1.size();
    int m = str2.size();

    if(dp[n][m] != -1) {
        return dp[n][m];
    }

    if(str1[n-1] == str2[m-1]) {
        dp[n][m] = 1 + lcsMem(str1.substr(0, n-1), str2.substr(0, m-1), dp);
    } else {
        int ans1 = lcsMem(str1.substr(0, n-1), str2, dp);
        int ans2 = lcsMem(str1, str2.substr(0, m-1), dp);
        dp[n][m] = max(ans1, ans2);
    }

    return dp[n][m];
}

// Longest Common Subsequence (Tabulation) - O(n*m)
int lcsTab(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main() {

    // Rod Cutting Problem
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    int rodLength = 8;

    cout << rodCutting(price, length, rodLength) << endl;

    cout << "------------------------------------------------------------" << endl;

    // Longest Common Subsequence (Recursion)
    string str1 = "abcdge";
    string str2 = "abedg";
    cout << lcsRec(str1, str2) << endl; // 4

    cout << "------------------------------------------------------------" << endl;

    // Longest Common Subsequence (Memoization)
    string str3 = "abcd";
    string str4 = "aceb";
    int n = str3.size();
    int m = str4.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1)); 
    cout << lcsMem(str3, str4, dp) << endl; // 2

    cout << "------------------------------------------------------------" << endl;

    // Longest Common Subsequence (Tabulation)
    cout << lcsTab(str1, str2) << endl; // 4
    cout << lcsTab(str3, str4) << endl; // 2

    cout << "------------------------------------------------------------" << endl;

    return 0;
}