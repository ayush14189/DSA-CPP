#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

    // Activity Selection Problem
    int maxActivities(vector<int> start, vector<int> end) {
        // Sort on basis of end time
        sort(end.begin(), end.end());
        // Select A0
        cout << "Selecting A0" << endl;
        int count = 1;
        int currEndTime = end[0];
        for(int i=1; i<start.size(); i++) {
            if (start[i] >= currEndTime) { // Non-Overlapping
                cout << "Selecting A" << i << endl;
                count++;
                currEndTime = end[i];
            }
        }
        return count;
    }

    // Pairs in C++
    bool compare1(pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second; // ascending - end

        // return p1.second > p2.second; // descending - end
        // return p1.first < p2.first; // ascending - start
        // return p1.first > p2.first; // descending - start
    } 

    // Fractional Knsapsack
    bool compare2(pair<double, int> p1, pair<double, int> p2) {
        return p1.first > p2.first; // descending - end
    } 

    int fractionalKnapsack(vector<int> val, vector<int> wt, int W) {
        int n = val.size();
        int ans = 0;
        // (ratio, idx) -> (double, int)
        vector<pair<double, int>> ratio(n, make_pair(0.0,0));
        // Calculate (val/wt)
        for(int i=0; i<n; i++) {                    // O(n)
            double r = (val[i]/wt[i]);
            ratio[i] = make_pair(r, i);
        }
        // Sort ratio in descending order
        sort(ratio.begin(), ratio.end(), compare2);  // O(nlogn)
        // Find ans
        for(int i=0; i<n; i++) {                    // O(n)
            int idx = ratio[i].second;
            if(wt[idx]<=W) {
                ans += val[idx];
                W -= wt[idx];
            } else {
                ans += (ratio[i].first*W);
                W=0;
                break;
            }
        }
        return ans;
    } 

    // Max Chain Length
    int maxChainLength(vector<pair<int,int>> pairs) {
        int n = pairs.size();
        // Sort on basis of end time
        sort(pairs.begin(), pairs.end(), compare1);
        // Select A0
        cout << "Selecting P0" << endl;
        int chainLength = 1;
        int currEnd = pairs[0].second;
        for(int i=1; i<n; i++) {
            if (pairs[i].first >= currEnd) { // Non-Overlapping
                cout << "Selecting P" << i << endl;
                chainLength++;
                currEnd = pairs[i].second;
            }
        }
        return chainLength;
    } 

    // Indian Coins
    int getMinChange(vector<int> coins, int V) {
        int ans = 0;
        int n = coins.size();
        for(int i=n-1; i>=0 && V>0; i--) {
            if(V>=coins[i]) {
                ans += (V/coins[i]);
                V = (V%coins[i]);
            }
        }
        return ans;
    }

    // Job Sequencing Problem


int main() {
    // Activity Selection Problem
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 7, 6, 9, 9};
    cout << maxActivities(start, end) << endl;

    // Pairs in C++
    vector<int> s = {0, 1, 2};
    vector<int> e = {9, 2, 4};

    vector<pair<int, int>> activity(3, make_pair(0,0));
    activity[0] = make_pair(0, 9);
    activity[1] = make_pair(1, 2);
    activity[2] = make_pair(2, 4);

    for(int i=0; i<activity.size(); i++) {
        cout << "A" << i << ": " << activity[i].first << ',' << activity[i].second << endl;
    }

    sort(activity.begin(), activity.end(), compare1);
    cout << "----Sorted----" << endl;
    for(int i=0; i<activity.size(); i++) {
        cout << "A" << i << ": " << activity[i].first << ',' << activity[i].second << endl;
    }

    // Fractional Knsapsack
    vector<int> val = {120, 100, 60};
    vector<int> wt = {30, 20, 10};
    int W = 50;
    cout << "Max possible value of knapsack = " << fractionalKnapsack(val, wt, W) << endl;

    // Min Absolute Difference Pairs - O(nlogn)
    // Ex 1 - ans = 6
    // vector<int> A = {4, 1, 8, 7};
    // vector<int> B = {2, 3, 6, 5};
    // Ex 2 - ans = 0
    vector<int> A = {1, 2, 3};
    vector<int> B = {3, 1, 2};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absDiff = 0;
    
    for(int i=0; i<A.size(); i++) {
        absDiff += abs(A[i]-B[i]);
    }
    cout << "Minimum Absolute Difference = " << absDiff << endl;

    // Max Chain Length
    vector<pair<int, int>> pairs(5, make_pair(0,0));
    pairs[0] = make_pair(5, 24);
    pairs[1] = make_pair(39, 60);
    pairs[2] = make_pair(5, 28);
    pairs[3] = make_pair(27, 40);
    pairs[4] = make_pair(50, 90);
    cout << maxChainLength(pairs) << endl;


    // Indian Coins
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    cout << "Min Change of Indian Coins" << endl;
    cout << getMinChange(coins, 1099) << endl;  // 8
    cout << getMinChange(coins, 590) << endl;   // 4
    cout << getMinChange(coins, 121) << endl;   // 3

    // Job Sequencing Problem
    

    return 0;
}