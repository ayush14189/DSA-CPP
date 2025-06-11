#include <iostream>
#include <vector>
using namespace std;

// Fractional Knapsack

// 0-1 Knapsack (Recursion)
int knapsackRec(vector<int> val, vector<int> wt, int W, int n) { // O(2^n)
    if(n == 0 || W == 0) {
        return 0;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= W) {
        // include
        int ans1 = knapsackRec(val, wt, W-itemWt, n-1) + itemVal;    
        // exclude
        int ans2 = knapsackRec(val, wt, W, n-1);    
        return max(ans1, ans2);
    } else {
        return knapsackRec(val, wt, W, n-1);    
    }
}

// 0-1 Knapsack (Memoization)
int knapsackMem(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>>& dp) { // O(n)
    if(n == 0 || W == 0) {
        return 0;
    }

    if(dp[n][W] != -1) {
        return dp[n][W];
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];
    
    if(itemWt <= W) {
        // include
        int ans1 = knapsackMem(val, wt, W-itemWt, n-1, dp) + itemVal;    
        
        // exclude
        int ans2 = knapsackMem(val, wt, W, n-1, dp);  

        dp[n][W] = max(ans1, ans2);
    } else {
        dp[n][W] = knapsackMem(val, wt, W, n-1, dp);    
    }

    return dp[n][W];
}

// 0-1 Knapsack (Tabulation)
int knapsackTab(vector<int> val, vector<int> wt, int W, int n) { // O(n*W)
    vector<vector<int>> dp(n+1, vector<int> (W+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j) {
                dp[i][j] = max(itemVal + dp[i-1][j-itemWt], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << "Tabulation Matrix:" << endl;
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<W+1; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }    

    return dp[n][W];
}

// Target Sum Subset
bool targetSum(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=target; j++) {
            if(nums[i-1] <= j) {
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=target; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][target] == target;
}

// Unbounded Knapsack
int unboundedKnapsack(vector<int> val, vector<int> wt, int W, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=0; j<W+1; j++) {
            int itemVal = val[i-1];
            int itemWt = wt[i-1];

            if(itemWt <= j) {
                dp[i][j] = max(itemVal + dp[i][j-itemWt], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {

    // 0-1 Knapsack (Recursion)
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int W = 7;
    int n = 5;
    cout << knapsackRec(val, wt, W, n) << endl;

    cout << "----------------------------------------------------" << endl;

    // 0-1 Knapsack (Memoization)
    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    cout << knapsackMem(val, wt, W, n, dp) << endl;

    cout << "Memoization Matrix:" << endl;
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<W+1; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "----------------------------------------------------" << endl;

    // 0-1 Knapsack (Tabulation)
    cout << knapsackTab(val, wt, W, n) << endl;

    cout << "----------------------------------------------------" << endl;

    // Target Sum Subset
    vector<int> nums = {4, 2, 7, 1, 3};
    int target = 10;
    cout << targetSum(nums, target) << endl; // 1
    cout << "----------------------------------------------------" << endl;
    int target2 = 25;
    cout << targetSum(nums, target2) << endl; // 0

    cout << "----------------------------------------------------" << endl;

    // Unbounded Knapsack
    cout << unboundedKnapsack(val, wt, W, n) << endl; // 100

    cout << "----------------------------------------------------" << endl;

    return 0;
}