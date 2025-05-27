#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Next Greater Element
void nextGreater(vector<int> arr, vector<int> ans) {
    stack<int> s;
    int idx = arr.size() - 1;
    ans[idx] = -1;
    s.push(arr[idx]);
    for (idx = idx-1; idx>=0; idx--) {
        int curr = arr[idx];
        while(!s.empty() && curr>=s.top()) {
            s.pop();
        }
        if(s.empty()) {
            ans[idx] = -1;
        } else {
            ans[idx] = s.top();
        }
        s.push(curr);
    }
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

// Valid Paranthesis - O(n)
bool isValid(string str) {
    stack<char> s;
    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        if(ch=='(' || ch=='[' || ch=='{') {
            s.push(ch);
        } else { // closing
            // corner case 
            if(s.empty()) {
                return false;
            } else {
                // matching
                char top = s.top();
                if((ch==')' && top=='(') || 
                    (ch==']' && top=='[') || 
                    (ch=='}' && top=='{')) {
                s.pop(); 
                } else {
                    return false;
                }
            }
        }
    }
    return s.empty();
}

// Duplicate Paranthesis - O(n)
bool isDuplicate(string str) {
    stack<char> s;
    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        if(ch != ')') { // Non-Closing
            s.push(ch);
        } else { // Closing
            if(s.top() == '(') {
                return true; // Duplicate
            }
            while(s.top() != '(') {
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}

void printArr(vector<int> arr){
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Max Area in Histogram
void maxAreaHistogram(vector<int> height) {
    int n = height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;

    // next smaller left
    nsl[0] = -1;
    s.push(0);
    for(int i=1; i<height.size(); i++) {
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }
        if(s.empty()){
            nsl[i] = -1;
        } else {
            nsl[i] = s.top();
        }
        s.push(i);
    }

    printArr(nsl);

    while(!s.empty()) {
        s.pop();
    }
    
    // next smaller right
    nsr[n-1] = n;
    s.push(n-1);
    for(int i=n-2; i>=0; i--) {
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }
        if(s.empty()){
            nsr[i] = n;
        } else {
            nsr[i] = s.top();
        }
        s.push(i);
    }

    printArr(nsr);

    int maxArea = 0;
    for(int i=0; i<n; i++) {
        int ht = height[i];
        int width = nsr[i] - nsl[i] - 1;
        int area = ht*width;
        maxArea = max(area, maxArea);
    }
    cout << "Maximum Area = " <<  maxArea;
}

int main() {
// Next Greater Element
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans = {0, 0, 0, 0, 0};
    nextGreater(arr, ans);
    
// Valid Paranthesis
    string str1= "([}])";       // false
    string str2= "([{}])";      // true
    string str3= "([{}])))";    // false
    string str4= "(([[{}])";    // false
    cout << isValid(str1) << endl;
    cout << isValid(str2) << endl;
    cout << isValid(str3) << endl;
    cout << isValid(str4) << endl;

// Duplicate Paranthesis
    string s1 = "((a+b))";          // true
    string s2 = "((a+b) + (c+d))";  // false
    cout << isDuplicate(s1) << endl; // 1
    cout << isDuplicate(s2) << endl; // 0

// Max Area in Histogram
    vector<int> height = {2, 1, 5, 6, 2, 3};
    maxAreaHistogram(height);

    return 0;
}