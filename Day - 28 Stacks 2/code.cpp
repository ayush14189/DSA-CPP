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

// Valid Paranthesis
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

// Duplicate Paranthesis
bool duplicate() {
    return;
}

// Max Area in Histogram

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

// Max Area in Histogram

    return 0;
}