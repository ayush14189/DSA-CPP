#include <iostream>
#include <string>
#include <cstring> // for strlen() function
using namespace std;

// Convert to Uppercase
void toUpper(char word[], int n) {
    for(int i=0; i<n; i++) {
        char ch = word[i];
        if(ch>='A' && ch<='Z') { // Uppercase
            continue;
        } else {                 // Lowercase   
            word[i] = ch - 'a' + 'A';
        }
    }
}

// Convert to Lowercase
void toLower(char word[], int n) {
    for(int i=0; i<n; i++) {
        char ch = word[i];
        if(ch>='a' && ch<='z') { // Uppercase
            continue;
        } else {                 // Lowercase   
            word[i] = ch - 'A' + 'a';
        }
    }
}

// Reverse a Char Array
void reverse(char word[], int n) {
    int start=0, end=n-1;
    while(start < end) {
        swap(word[start++], word[end--]);
        // swap(word[start], word[end]);
        // start++;
        // end--;
    }
}

// Valid Palindrome
bool isPalindrome(char word[], int n) {
    int start=0, end=n-1;
    while(start < end) {
        if(word[start++] != word[end--]) {
            cout << "Not Valid Palindrome" << endl;
            return false;
        }
        // start++;
        // end--;
    }
    cout << "Valid Palindrome" << endl;
    return true;
}

// Valid Anagram
bool isAnagram(string str1, string str2) {
    if(str1.length() != str2.length()) {
        cout << "Not Valid Anagrams";
        return false;
    }
    int count[26] = {0};
    for(int i=0; i<str1.length(); i++) {
        count[str1[i] - 'a']++;
    }
    for(int i=0; i<str2.length(); i++) {
        if(count[str2[i] - 'a']==0) {
            cout << "Not Valid Anagrams";
            return false;
        }
        count[str1[i] - 'a']--;
    }
    cout << "Valid Anagrams" << endl;
    return true;
}

int main() {
    char t = '\n'; // newline character
    char ch = 'A';
    cout << (int)ch << endl;
    char ch1 = 'f';
    int pos = ch1 - 'a';
    cout << pos << endl;

    // Character Arrays
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    cout << arr << endl; // Not a String
    
    char a[5] = {'c', 'o', 'd', 'e', '\0'};
    char b[5] = "code";
    cout << a << endl;   // code is a String
    cout << strlen(a) << endl;

    "helloworld";        // String Literal
    "abcd efgh";         // String Literal
    "apna college";      // String Literal

    // Input Character Array
    char word[10];
    cin >> word;          // Ignore Whitespaces
    char sentence[50];
    cin.getline(sentence, 50, '.');

    // cout << "Your word is: " << word << endl;
    // cout << "Length: " << strlen(word) << endl;
    // cout << "Your word is: " << sentence << endl;
    // cout << "Length: " << strlen(sentence) << endl;
    // cout << "0th Element: " << sentence[0] << endl;

    // Convert to UpperCase
    char x[] = "ApPle";
    toUpper(x, strlen(x));
    cout << x << endl;
    toLower(x, strlen(x));
    cout << x << endl;

    // Reverse a Char Array
    char w[] = "code";
    cout << "Word: " << w << endl;
    reverse(w, strlen(w));
    cout << "Reversed word: " << w << endl;

    // Valid Palindrome
    char p[] = "racecar";
    char q[] = "apple";
    cout << "racecar: ";
    isPalindrome(p, strlen(p)); // 1 - true
    cout << "apple: ";
    isPalindrome(q, strlen(q));   // 0 - false 

    // <cstring> Functions
    char str1[100];
    char str2[100] = "it is a string";
    // strcpy - copy
    strcpy(str1, str2);
    cout << str1 << endl;   
    strcpy(str1, "hello world");  // str1 = "hello world";
    cout << str1 << endl;
    // strcat - concatenate
    strcat(str1, str2);
    cout << str1 << endl;
    cout << str2 << endl;
    // strcmp - comparison
    cout << strcmp(str1, str2) << endl;
    char x1[] = "mango";
    char y1[] = "pineapple";
    cout << strcmp(x1, y1) << endl;

    // C++ Strings
    string s = "hello";
    cout << s << endl;
    s = "yellow"; // Reallocation with Dynamic Size
    cout << s << endl;

    // Input a String
    string s1;
    string s2;
    // cout << "Enter the string: ";
    // cin >> s1;
    // cout << "You entered: " << s1 << endl;
    cout << "Enter the string:";
    getline(cin, s2, '*');
    cout << "You entered: " << s2 << endl;
    cout << "1st element: " << s2[1] << endl;
    cout << "2nd element: " << s2[2] << endl;

    // for each Loop
    string xyz = "Ayush Jain";

    for(int i=0; i < xyz.length(); i++) {
        cout << xyz[i] << "-";
    }
    cout << endl;

    for(char ch : xyz) {
        cout << ch << "-";
    }
    cout << endl;

    // String Member Functions
    string abc = "I love coding in C++ & C++";
    cout << xyz.length() << endl;
    cout << xyz.at(3) << endl;
    cout << xyz.substr(2, 6) << endl;
    cout << abc.find("C++") << endl;     // 17
    cout << abc.find("C++", 20) << endl; // 23
    int idx = abc.find("Python");
    cout << idx << endl;  // -1

    // Valid Anagram
    string w1 = "anagram", w2 = "nagaram";
    string a1 = "car", a2 = "rat";
    cout << "Strings: " << "w1 = " << w1 << ", w2 = " << w2 << endl;
    isAnagram(w1, w2); // Valid Anagrams
    cout << "Strings: " << "w1 = " << w1 << ", w2 = " << w2 << endl;
    isAnagram(a1, a2); // Not Valid Anagrams

    // Operators in Strings
    string b1= "cat", b2 = "dog";
    cout << (b1 == b2) << endl; // 0
    cout << (b1 != b2) << endl; // 1
    cout << (b1 >= b2) << endl; // 0
    cout << (b1 <= b2) << endl; // 1
    cout << (b1 > b2) << endl;  // 0
    cout << (b1 < b2) << endl;  // 1
    cout << (b1 + b2) << endl;  // catdog - concatenation
        
    return 0;
}