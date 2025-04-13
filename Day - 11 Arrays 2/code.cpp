#include<iostream>
using namespace std;

void printSubarrays(int *arr, int n) {
    for(int start=0; start<n; start++) {
        for(int end=start; end<n; end++) {
            for(int i=start; i<=end; i++) {
                cout << arr[i];
            }
            cout << ", ";
        }
        cout << endl;
    }
}

// Brute Force Approach
void maxSubarraySum1(int *arr, int n) {
    int maxSum = INT16_MIN;
    for(int start=0; start<n; start++) {
        for(int end=start; end<n; end++) {
            int currSum = 0;
            for(int i=start; i<=end; i++) {
                currSum+=arr[i];
            }
            cout << currSum << "\t";
            maxSum = max(maxSum, currSum);
        }
        cout << endl;
    }
    cout << "Maximum Subarray Sum (Brute Force) = " << maxSum << endl;
}

// Slightly Optimized Approach
void maxSubarraySum2(int *arr, int n) {
    int maxSum = INT16_MIN;
    for(int start=0; start<n; start++) {
        int currSum = 0;
        for(int end=start; end<n; end++) {
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
    }
    cout << "Maximum Subarray Sum (Slightly Optimized) = " << maxSum << endl;
}

// Kadane's Algorithm (DP)
void maxSubarraySum3(int *arr, int n) {
    int maxSum = INT16_MIN, currSum = 0;
    for(int i=0; i<n; i++) {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if(currSum < 0) {
            currSum = 0;
        }
    }
    cout << "Maximum Subarray Sum (Kadane's Algorithm) = " << maxSum << endl;
}

// Buy & Sell Stocks
void maxProfit(int *prices, int n) {
    int bestBuy[100000];
    bestBuy[0] = INT16_MAX;
    for(int i=1; i<n; i++) {
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
    }
    int maxProfit = 0;
    for(int i=0; i<n; i++) {
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }
    cout << "Maximum Profit = " << maxProfit << endl;
}

// Trapping Rainwater
void trap(int *heights, int n) {

    int leftMax[20000], rightMax[20000];
    leftMax[0] = heights[0];
    rightMax[n-1] = heights[n-1];

    for(int i=1; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], heights[i-1]);
    }
    for(int i=n-2; i>=0; i--) {
        rightMax[i] = max(rightMax[i+1], heights[i+1]);
    }

    int waterTrapped = 0;
    for(int i=0; i<n; i++) {
        int currWater = min(leftMax[i], rightMax[i]) - heights[i];
        if(currWater > 0) {
            waterTrapped += currWater;
        }
    }
    cout << "Water Trapped = " << waterTrapped << endl;    
}

int main() {
    // Print Subarrays
    // int a[] = {};
    // int length = sizeof(a)/sizeof(length);
    // printSubarrays(a, length);

    // Max Subarray Sum
    int b[] = {2, -3, 6, -5, 4, 2};
    int len = sizeof(b)/sizeof(int);
    maxSubarraySum1(b, len);
    maxSubarraySum2(b, len);
    maxSubarraySum3(b, len);

    // Buy and Sell Stocks
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices)/sizeof(int); 
    maxProfit(prices, n);

    // Trapping Rainwater
    int heights[] = {4, 2, 0, 6, 3, 2, 5};
    int l = sizeof(heights)/sizeof(int);
    trap(heights, l);

    return 0;
}