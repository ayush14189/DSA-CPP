#include <iostream>
#include <vector>
using namespace std;

// Fibonacci using Recursion
int fib(int n) { // O(2^n)
    if(n == 0 || n == 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

// Fibonacci using Memoization
int fibDP(int n, vector<int>& f) { // O(n)
    if(n == 0 || n == 1) {
        return n;
    }

    if(f[n] != -1) {
        return f[n];
    }

    f[n] = fibDP(n-1, f) + fibDP(n-2, f);
    return f[n];
}

// Fibonacci using Tabulation
int fibTab(int n) { // O(n)
    vector<int> fib(n+1, 0);
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i=2; i<=n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}

// Climbing Stairs with Recursion - O(2^n)
int countWaysRec(int n) {
    if(n==1 || n==0) {
        return 1;
    }
    return countWaysRec(n-1) + countWaysRec(n-2);
}

// Climbing Stairs with Memoization - O(n)
int countWaysMem(int n, vector<int>& dp) {
    if(n == 1 || n == 0) {
        return 1;
    }
    
    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = countWaysMem(n-1, dp) + countWaysMem(n-2, dp);
    return dp[n];
}

// Climbing Stairs with Tabulation - O(n)
int countWaysTab(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// Climbing Stairs Variation with Tabulation - O(n)
int countWaysTabVar(int n) { // 1, 2, 3 jumps allowed
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main() {
    int n = 6;
    
    // Fibonacci using Recursion
    cout << fib(n) << endl;

    // Fibonacci using DP
    vector<int> f(n+1, -1);
    cout << fibDP(n, f) << endl; 

    cout << fibTab(n) << endl; 

    cout << "---------------------------------------------" << endl;

    // Climbing Stairs with Recursion
    cout << "Climbing Stairs with Recursion: " << endl;
    cout << countWaysRec(4) << endl;
    cout << countWaysRec(5) << endl;
    cout << countWaysRec(3) << endl;

    cout << "---------------------------------------------" << endl;

    // Climbing Stairs with Memoization
    vector<int> dp(n+1, -1);
    cout << "Climbing Stairs with Memoization: " << endl;
    cout << countWaysMem(4, dp) << endl;
    cout << countWaysMem(5, dp) << endl;
    cout << countWaysMem(3, dp) << endl;

    cout << "---------------------------------------------" << endl;

    // Climbing Stairs with Tabulation
    cout << "Climbing Stairs with Tabulation: " << endl;
    cout << countWaysTab(4) << endl;
    cout << countWaysTab(5) << endl;
    cout << countWaysTab(3) << endl;

    cout << "---------------------------------------------" << endl;

    // Climbing Stairs Variation with Tabulation
    cout << "Climbing Stairs Variation with Tabulation: " << endl;
    cout << countWaysTabVar(4) << endl;
    cout << countWaysTabVar(5) << endl;
    cout << countWaysTabVar(3) << endl;
    
    return 0;
}