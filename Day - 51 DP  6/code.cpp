#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Matrix Chain Multiplication (Recursion)
int mcmRec(vector<int> arr, int i, int j) {
    if(i==j) {
        return 0;
    }

    int ans = INT_MAX;

    for(int k=i; k<j; k++) {
        // (i, k)
        int cost1 = mcmRec(arr, i, k);

        // (k+1, j)
        int cost2 = mcmRec(arr, k+1, j);
        
        // curr Partition Cost
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, currCost);
    }

    return ans;
}

// Matrix Chain Multiplication (Memoization)
int mcmMem(vector<int> arr, int i, int j, vector<vector<int>> &dp) {
    if(i == j) {
        return 0;
    }
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = INT_MAX;

    for(int k=i; k<j; k++) {
        // (i, k)
        int cost1 = mcmMem(arr, i, k, dp);

        // (k+1, j)
        int cost2 = mcmMem(arr, k+1, j, dp);
        
        // curr Partition Cost
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, currCost);
    }

    return dp[i][j] = ans;
}

// Matrix Chain Multiplication (Tabulation)
int mcmTab(vector<int> arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialization
    for(int i=1; i<n; i++) {
        dp[i][i] = 0;
    }

    // Bottom Up Fill
    for(int len=2; len<n; len++) {
        for(int i=1; i<=n-len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++) {
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int currCost = cost1 + cost2 + (arr[i-1] * arr[j] * arr[k]);
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    return dp[1][n-1];
}

// Minimum Partitioning
int getMinDiff(vector<int> nums) {
    int totSum = 0;
    for(int el : nums) {
        totSum += el;
    }

    int n = nums.size();
    int W = totSum / 2;
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            if(nums[i-1] <= j) {
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int grp1Sum = dp[n][W];
    int grp2Sum = totSum - grp1Sum;
    return abs(grp1Sum - grp2Sum);
}

int main() {
    // Matrix Chain Multiplication (Recursion)
    
    vector<int> arr = {1, 2, 3, 4, 3}; // n -> n-1 matrices (1 to n-1)
    int n = arr.size();
    cout << "MCM with Recursion = " << mcmRec(arr, 1, n-1) << endl;

    cout << "--------------------------------------------------------" << endl;
    
    // Matrix Chain Multiplication (Memoization)

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "MCM with Memoization = " << mcmMem(arr, 1, n-1, dp) << endl;

    cout << "--------------------------------------------------------" << endl;

    // Matrix Chain Multiplication (Tabulation)

    cout << "MCM with Tabulation = " << mcmTab(arr) << endl;

    cout << "--------------------------------------------------------" << endl;

    // Minimum Partitioning

    vector<int> nums = {1, 6, 11, 5};
    cout << getMinDiff(nums) << endl;  // 1
    vector<int> nums2 = {1, 2, 3};
    cout << getMinDiff(nums2) << endl; // 0

    return 0;
}