#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Wildcard Matching - Leetcode 
bool isMatch(string t, string p) { // O(n*m)
    int n = t.size();
    int m = p.size();

    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;    

    for(int j=1; j<m+1; j++) { // 0th Row => text is ""
        if(p[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        } else { // '?' or char
            dp[0][j] = false;
        }
    }

    // Bottom Up Manner to fill DP
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(t[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            } else if(p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            } else {
                dp[i][j] = false;
            }
        }
    }

    for(int i=0; i<n+1; i++) {
        for(int j=0; j<m+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][m];
}

// Nth catalan (Recursion)
int catalanRec(int n) {
    if(n==0 || n==1) {
        return 1;
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        ans += catalanRec(i) * catalanRec(n-i-1);
    }

    return ans;
}

// Nth catalan (Memoization)
int catalanMem(int n, vector<int> &dp) {
    if(n==0 || n==1) {
        return 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        ans += catalanMem(i, dp) * catalanMem(n-i-1, dp);
    }
 
    return ans;
}

// Nth catalan (Tabulation)
int catalanTab(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++) {       // ith Catalan
        for(int j=0; j<i; j++) {    // 0 to i-1
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

// Count BSTs from Nodes
int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++) {       // ith Catalan
        for(int j=0; j<i; j++) {    // 0 to i-1
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

// Mountain Ranges
int mountainRanges(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++) {       // ith Catalan
        for(int j=0; j<i; j++) {    // 0 to i-1
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int main() {
    
    // Wildcard Matching
    string t = "abcd";
    string p = "*b*?";
    cout << "Wildcard Match: " << isMatch(t, p) << endl; // 1
    
    cout << "--------------------------------------------------------" << endl;

    // Nth catalan (Recursion)
    cout << "Catalan Numbers: ";
    for(int i=0; i<=6; i++) {
        cout << catalanRec(i) << " ";
    }
    cout << endl;
    
    cout << "--------------------------------------------------------" << endl;
    
    // Nth catalan (Memoization)
    int n = 6;
    vector<int> dp(n+1, -1);
    cout << "Catalan Numbers: ";
    for(int i=0; i<=n; i++) {
        cout << catalanMem(i, dp) << " ";
    }
    cout << endl;
    
    cout << "--------------------------------------------------------" << endl;
    
    // Nth catalan (Tabulation)
    cout << "Catalan Numbers: ";
    for(int i=0; i<=6; i++) {
        cout << catalanTab(i) << " ";
    }
    cout << endl;

    cout << "--------------------------------------------------------" << endl;
    
    // Count BSTs from Nodes
    cout << "Number of BSTs: ";
    for(int i=0; i<=6; i++) {
        cout << numTrees(i) << " ";
    }
    cout << endl;

    cout << "--------------------------------------------------------" << endl;

    // Mountain Ranges
    cout << "Mountain Ranges: ";
    for(int i=0; i<=6; i++) {
        cout << numTrees(i) << " ";
    }
    cout << endl;
    
    cout << "--------------------------------------------------------" << endl;

    return 0;
}