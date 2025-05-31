#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
using namespace std;

// Majority Element
void majorityElement(vector<int> nums) {
    unordered_map<int, int> m; // <element, freq>

    for(int i=0; i<nums.size(); i++) {
        if(m.count(nums[i])) {
            m[nums[i]]++;
        } else {
            m[nums[i]] = 1;
        } 
    }
    
    for(pair<int, int> p : m) {
        if(p.second > nums.size()/3) {
            cout << p.first << " ";
        }
    }
    cout << endl;
}

// Valid Anagram
bool validAnagram(string s, string t) {
    
    if(s.size() != t.size()) {
        return false;
    }

    // s <char, freq>
    unordered_map<char, int> freq;
    for(int i=0; i<s.size(); i++) {
        if(freq.count(s[i])) {
            freq[s[i]]++;
        } else {
            freq[s[i]] = 1;
        }
    } 
    
    // Look for t's chars in freq
    for(int i=0; i<t.size(); i++) {
        if(freq.count(t[i])) {
            freq[t[i]]--;
            if(freq[t[i]] == 0) {
                freq.erase(t[i]);
            }
        } else {
            return false;
        }
    }
    return freq.size() == 0;
}

// Count Distinct
int countDistinct(vector<int> arr) {
    unordered_set<int> s;
    for(int i=0; i<arr.size(); i++) {
        s.insert(arr[i]);
    }
    for(int el : s) {
        cout << el << " ";
    }
    cout << endl;
    return s.size();
}

// Union & Intersection
void printUnion(vector<int> arr1, vector<int> arr2) {
    unordered_set<int> s;
    for(int el : arr1) {
        s.insert(el);
    }
    for(int el : arr2) {
        s.insert(el);
    }
    for(int el : s) {
        cout << el << " ";
    }
    cout << endl;
}

void printIntersection(vector<int> arr1, vector<int> arr2) {
    unordered_set<int> s;
    for(int el : arr1) {
        s.insert(el);
    }
    for(int el : arr2) {
        if(s.find(el) != s.end()) {
            cout << el << " ";
            s.erase(el);
        }
    }
    cout << endl;
}

// itinerary from Tickets
void printItinerary(unordered_map<string, string> tickets) {
    // Starting Point
    unordered_set<string> to;
    for(pair<string, string> ticket : tickets) {
        to.insert(ticket.second);
    } 
    string start = "";
    for(pair<string, string> ticket : tickets) {
        if(to.find(ticket.first) == to.end()) {
            start = ticket.first;
        }
    } 

    // Print Plan
    cout << start << " -> ";
    while(tickets.count(start)) {
        cout << tickets[start] << " -> ";
        start = tickets[start];
    }
    cout << "destination" << endl;
}

// Zero Sum Largest Subarray
int largestSubWith0Sum(vector<int> arr) {
    unordered_map<int, int> m;
    int sum = 0;
    int ans = 0;

    for(int j=0; j<arr.size(); j++) {
        sum += arr[j];

        if(m.count(sum)) {
            int currLength = j-m[sum]; // (j-idx)
            ans = max(ans, currLength);
        } else {
            m[sum] = j;
        }
    }
    return ans;
}

// K Sum Subarray Count
int subarrayCountWithK(vector<int> arr, int K) {
    unordered_map<int, int> m;
    m[0] = 1;
    int sum = 0;
    int ans = 0;

    for(int j=0; j<arr.size(); j++) {
        sum += arr[j];
        if(m.count(sum-K)) {
            ans += m[sum-K];  
        }
        if(m.count(sum)) {
            m[sum]++;
        } else {
            m[sum] = 1;
        }
    }
    return ans;
}

int main() {

    // Majority Element
    vector<int> nums = {1, 3, 2, 5, 1, 3, 1, 5, 1};
    vector<int> nums2 = {1, 2};
    majorityElement(nums);
    majorityElement(nums2);

    cout << "-------------------------------------" << endl;

    // Valid Anagram
    string s1 = "race";
    string s2 = "care";
    cout << validAnagram(s1, s2) << endl;
    string s3 = "tulip";
    string s4 = "lipid";
    cout << validAnagram(s3, s4) << endl;

    cout << "-------------------------------------" << endl;

    // Count Distinct
    vector<int> arr = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};
    cout << "Count of distinct values: " << countDistinct(arr) << endl;

    cout << "-------------------------------------" << endl;

    // Union & Intersection
    vector<int> a = {7, 3, 9};
    vector<int> b = {6, 3, 9, 2, 9, 4};
    cout << "Union = ";
    printUnion(a, b);
    cout << "Intersection = ";
    printIntersection(a, b);

    cout << "-------------------------------------" << endl;

    // itinerary from Tickets
    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";
    printItinerary(tickets);

    cout << "-------------------------------------" << endl;

    // Zero Sum Largest Subarray
    vector<int> x = {15, -2, 2, -8, 1, 7, 10};
    cout << "Largest Subarray with Sum 0 = " << largestSubWith0Sum(x) << endl;

    cout << "-------------------------------------" << endl;

    // K Sum Subarray Count
    vector<int> y = {10, 2, -2, -20, 10};
    vector<int> z = {1, 2, 3};
    
    cout << "Count of Subarray Sum K = " << subarrayCountWithK(y, -10) << endl;
    cout << "Count of Subarray Sum K = " << subarrayCountWithK(z, 3) << endl;

    cout << "-------------------------------------" << endl;
    
    return 0;
}