#include <iostream>
using namespace std;

// Tiling Problem
int tilingProblem(int n) {
    if(n==0 || n==1) {
        return 1;
    }
    return tilingProblem(n-1) + tilingProblem(n-2);
    // // Vertical
    // int ans1 = tilingProblem(n-1); // 2x(n-1)
    // // Horizontal
    // int ans2 = tilingProblem(n-2); // 2x(n-2)
}

// Remove Duplicates in String
void removeDuplicates(string str, string ans, int i, int map[26]) {
    if(i==str.size()) { // Base Case
        cout << "Ans: " << ans << endl;
        return;
    }
    int mapIdx = (int)(str[i] - 'a');
    if(map[mapIdx]) { // Duplicate
        return removeDuplicates(str, ans, i+1, map);
    } else {          // Not Duplicate
        map[mapIdx] = true;
        return removeDuplicates(str, ans+str[i], i+1, map);
    }
}

// Remove duplicates in a String
void removeDuplicates2(string str, string ans, int map[26]) {
    if(str.size()==0) { // Base Case
        cout << "Ans: " << ans << endl;
        return;
    }
    int n = str.size();
    char ch = str[n-1];
    int mapIdx = (int)(str[n-1] - 'a');
    str = str.substr(0, n-1);
    if(map[mapIdx]) { // Duplicate
        return removeDuplicates2(str, ans, map);
    } else {          // Not Duplicate
        map[mapIdx] = true;
        return removeDuplicates2(str, ch+ans, map);
    }
}

// Friends Pairing Problem
int friendsPairingProblem(int n) {
    if(n==1 || n==2) {
        return n;
    }
    return friendsPairingProblem(n-1) + (n-1) * friendsPairingProblem(n-2);
}

// Binary Strings Problem
void binString(int n, int lastPlace, string ans) {
    if(n==0) {
        cout << ans << endl;
        return;
    }
    if(lastPlace != 1){
        binString(n-1, 0, ans + '0');
        binString(n-1, 1, ans + '1');
    } else {
        binString(n-1, 0, ans + '0');
    }
}

void binString2(int n, string ans) {
    if(n==0) {
        cout << ans << endl;
        return;
    }
    if(ans[ans.size()-1] != '1'){
        binString2(n-1, ans + '0');
        binString2(n-1, ans + '1');
    } else {
        binString2(n-1, ans + '0');
    }
}

int main() {

    // Tiling Problem
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << tilingProblem(n) << endl;
    
    // Remove duplicates in a String
    // Approach 1
    string str = "appnnacollege";
    // string str2 = "aaabbbbcccdddd";
    string ans = "";
    int map[26] = {false};
    removeDuplicates(str, ans, 0, map);
    // removeDuplicates(str2, ans, 0, map);

    // Approach 2
    string str2 = "appnnacollege";
    string ans2 = "";
    int map2[26] = {false};
    removeDuplicates2(str2, ans2, map2);

    // Friends Pairing Problem
    int m;
    cout << "Enter no of candidates: ";
    cin >> m;
    cout << "No of ways of pairing = " << friendsPairingProblem(m) << endl;

    // Binary String Problem
    string ans1 = "";
    binString(3, 0, ans1);
    binString2(3, ans1);
    
    return 0;
}