#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

// Longest Common Substring
int longestCommonSubstring(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    int ans = 0;

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<m+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return ans;
}

// Longest Increasing Subsequence
int LIS(vector<int> arr) {
    unordered_set<int> s(arr.begin(), arr.end()); // Unique - O(n)

    vector<int> arr2(s.begin(), s.end());
    sort(arr2.begin(), arr2.end()); // Ascending Sorted Order - O(nlogn)

    // LCS => LIS
    int n = arr.size();
    int m = arr2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i=1; i<n+1; i++) { // O(n*n)
        for(int j=1; j<m+1; j++) {
            if(arr[i-1] == arr2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

// Edit Distance - LeetCode 72
int minDistance(string word1, string word2) { // O(n*m)
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j=0; j<m+1; j++) { // 0th row initialize - insert
        dp[0][j] = j;
    }

    for(int i=0; i<n+1; i++) { // 0th col initialize - delete
        dp[i][0] = i;
    }

    // Bottom-Up Approach
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(word1[i-1] == word2[j-1]) {
                dp[i][j] = 0 + dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];
}

int main() {
    // Longest Common Substring
    string str1 = "abcde";
    string str2 = "abgce";
    cout << "LCS = " << longestCommonSubstring(str1, str2) << endl; // 4

    cout << "--------------------------------------------------------" << endl;

    // Longest Increasing Subsequence
    vector<int> arr = {50, 3, 10, 7, 40, 80};
    cout << "LIS = " << LIS(arr) << endl;

    cout << "--------------------------------------------------------" << endl;

    // Edit Distance
    string s1 = "horse";
    string s2 = "ros";
    cout << "Min Distance = " << minDistance(s1, s2) << endl;

    cout << "--------------------------------------------------------" << endl;

    return 0;
}