#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Building a Trie
class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    
    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();    
    }

    // Insert in Trie
    void insert(string key) {
        Node* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(!temp->children.count(key[i])) {
                temp->children[key[i]] = new Node(); // insert
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    // Search in Trie
    bool search(string key) {   
        Node* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i])) {
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }
        return temp->endOfWord;
    }

    // StartsWith Problem
    bool startsWith(string prefix) { // O(L)
        Node* temp = root;

        for(int i=0; i<prefix.size(); i++) {
            if(temp->children[prefix[i]]) {
                temp = temp->children[prefix[i]];
            } else {
                return false;
            }
        }
        return true;
    }

    // Longest word with all Prefix
    void longestHelper(Node* root, string &ans, string temp) {
        for(pair<char, Node*> child : root->children) {
            if(child.second->endOfWord) {
                temp += child.first;
            
                if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())) {
                    ans = temp;
                }

                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size()-1);
            }
        }
    }

    string longestStringWithEOW() {
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }
};

// Word Break Problem
bool helper(Trie &trie, string key) {
    if(key.size() == 0) {
        return true;
    }
    for(int i=0; i<key.size(); i++) {
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);
        if(trie.search(first) && helper(trie, second)) {
            return true;
        }
    }
    return false;
}
bool wordBreak(vector<string> dict, string key) {
    Trie trie;
    for(int i=0; i<dict.size(); i++) {
        trie.insert(dict[i]);
    }
    return helper(trie, key);
}

// Prefix Problem
class Node2{
public:
    unordered_map<char, Node2*> children;
    bool endOfWord;
    
    int freq; // Prefix Problem

    Node2() {
        endOfWord = false;
    }
};

class Trie2 {
    Node2* root;
public:
    Trie2() {
        root = new Node2();
        root->freq = -1; // Prefix Problem
    }

    // Insert in Trie
    void insert(string key) {
        Node2* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(!temp->children.count(key[i])) {
                temp->children[key[i]] = new Node2(); // Insert
                temp->children[key[i]]->freq = 1;    // Prefix Problem
            } else {
                temp->children[key[i]]->freq++;      // Prefix Problem
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    // Search in Trie
    bool search(string key) {   
        Node2* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i])) {
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }
        return temp->endOfWord;
    }
    
    // Get Prefix
    string getPrefix(string key) { // O(L)
        Node2* temp = root;
        string prefix = "";

        for(int i=0; i<key.size(); i++) {
            prefix += key[i];
            if (temp->children[key[i]]->freq == 1) {
                break;
            }
            temp = temp->children[key[i]];
        }
        return prefix; 
    }
};

void prefixProblem(vector<string> dict) { // O(n*L)
    Trie2 trie;
    for(int i=0; i<dict.size(); i++) {
        trie.insert(dict[i]); 
    }
    for(int i=0; i<dict.size(); i++) {
        cout << trie.getPrefix(dict[i]) << endl;
    }
}

// Count Unique Substrings


// Longest word with all Prefix
string longestString(vector<string> dict) {
    Trie trie;
    for(int i=0; i<dict.size(); i++) {
        trie.insert(dict[i]);
    }

    return trie.longestStringWithEOW();
}

int main() {

    // Building a Trie
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;

    // Insert in Trie
    for(int i=0; i<words.size(); i++) {
        trie.insert(words[i]);
    }

    // Search in Trie
    cout << trie.search("there") << endl;
    cout << trie.search("any") << endl;
    cout << trie.search("ant") << endl;

    cout << "-------------------------------------" << endl;

    // Word Break Problem
    vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
    cout << wordBreak(dict, "ilikesamsung") << endl; // 1
    cout << wordBreak(dict, "ilikesam") << endl;     // 1
    cout << wordBreak(dict, "ilikesung") << endl;    // 0


    cout << "-------------------------------------" << endl;

    // Prefix Problem
    vector<string> word = {"zebra", "dog", "dove", "duck"};
    prefixProblem(word);

    cout << "-------------------------------------" << endl;

    // Starts With Problem
    vector<string> str = {"apple", "app", "mango", "man", "woman"};
    Trie t;
    for(int i=0; i<str.size(); i++){
        t.insert(str[i]);
    }
    cout << t.startsWith("app") << endl;  // 1
    cout << t.startsWith("moon") << endl; // 0
    cout << t.startsWith("wom") << endl;  // 1

    cout << "-------------------------------------" << endl;

    // Count Unique Substrings

    cout << "-------------------------------------" << endl;

    // Longest word with all Prefix
    vector<string> vec = {"a", "banana", "app", "ap", "appl", "apply", "apple"};
    cout << longestString(vec) << endl;  // apple
    vector<string> vec2 = {"a", "banana", "app", "ap", "appl", "apply"};
    cout << longestString(vec2) << endl; // apply
    
    cout << "-------------------------------------" << endl;
    
    return 0;
}