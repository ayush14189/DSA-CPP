#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

// Building Hash Tables
class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int totSize;
    int currSize; // Rehashing
    Node** table;

    int HashFunction(string key) {
        int idx = 0;

        for(int i=0; i<key.size(); i++) {
            idx = idx + (key[i] * key[i]) % totSize;
        }
        return idx % totSize;
    }

    // Rehashing
    void rehash() { // O(n)
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2*totSize;
        currSize = 0;
        table = new Node*[totSize];
        
        for(int i=0; i<totSize; i++) {
            table[i] = NULL;
        }

        // Copy old values        
        for(int i=0; i<oldSize; i++) {
            Node* temp = oldTable[i];
            while(temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:

    // Insert in Hash Table
    HashTable(int size=5) {
        totSize = size;
        currSize = 0;

        table = new Node*[totSize];

        for(int i=0; i<totSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) { // O(1) - avg case
        int idx = HashFunction(key);
        
        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize / (double)totSize;
        if(lambda > 1) {
            rehash(); // O(n) - worst case
        }
    }
    
    // Search in Hash Table
    bool exists(string key) {
        int idx = HashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL) {
            if(temp->key == key) { // Found
                return true;
            }
            temp = temp->next;
        } 
        return false;
    }

    int search(string key) {
        int idx = HashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL) {
            if(temp->key == key) { // Found
                return temp->val;
            }
            temp = temp->next;
        } 
        return -1;
    }
    
    // Remove in Hash Table
    void remove(string key) {
        int idx = HashFunction(key);
        
        Node* temp = table[idx];
        Node* prev = temp;
        while(temp != NULL) {
            if(temp->key == key) { // erase
                if(prev == temp) { // head
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    // Print Hash Table
    void print() {
        for(int i=0; i<totSize; i++) {
            cout << "idx " << i << "->";
            Node* temp = table[i];
            while(temp != NULL) {
                cout << "(" <<temp->key << "," << temp->val << ")" << "->"; 
                temp = temp->next;
            }
        cout << endl;
        }
    }
};

int main() {
    // Building Hash Tables
    HashTable ht;

    cout << "-------------------------------------" << endl;

    // Insert & Rehashing in Hash Table
    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("Nepal", 10);
    ht.insert("USA", 50);
    ht.insert("UK", 20);

    // Search in Hash Table
    if(ht.exists("India")) {
        cout << "India Population: " << ht.search("India") << endl;
        cout << "China Population: " << ht.search("China") << endl;
        cout << "USA Population: " << ht.search("USA") << endl;
        cout << "Nepal Population: " << ht.search("Nepal") << endl;
    }

    cout << "-------------------------------------" << endl;
    
    // Print a Hash Table

    cout << "Hash Table:" << endl;
    ht.print();

    cout << "-------------------------------------" << endl;

    // Remove in Hash Table
    cout << "After removing China:" << endl;
    ht.remove("China");
    ht.print();

    cout << "-------------------------------------" << endl;

    cout << "After removing UK:" << endl;
    ht.remove("UK");
    ht.print();

    cout << "-------------------------------------" << endl;

    // Unordered Maps
    unordered_map<string, int> m; // Build
    m["China"] = 150;             // Insert
    m["India"] = 150;
    m["USA"] = 50;
    m["Nepal"] = 10;
    m["UK"] = 20;
    
    // Search Unordered Map
    cout << "India Population: " << m["India"] << endl;
    for(pair<string, int> country : m) {
        cout << country.first << ", " << country.second << endl;
    }

    // Count
    if(m.count("Nepal")) {
        cout << "Nepal exists" << endl;
    } else {
        cout << "Nepal doesn't exists" << endl;
    }

    if(m.count("Canada")) {
        cout << "Canada exists" << endl;
    } else {
        cout << "Canada doesn't exists" << endl;
    }

    // Remove
    m.erase("Nepal");
    if(m.count("Nepal")) {
        cout << "Nepal exists" << endl;
    } else {
        cout << "Nepal doesn't exists" << endl;
    }

    // Update
    m["China"] = 200;
    cout << "Update value of China: " << m["China"] << endl;

    cout << "-------------------------------------" << endl;

    // Maps
    map<string, int> n; // Build
    n["China"] = 150;             // Insert
    n["India"] = 150;
    n["USA"] = 50;
    n["Nepal"] = 10;
    n["UK"] = 20;
    
    // Search Unordered Map
    cout << "India Population: " << n["India"] << endl;
    for(pair<string, int> country : n) {
        cout << country.first << ", " << country.second << endl;
    }

    // Count
    if(n.count("Nepal")) {
        cout << "Nepal exists" << endl;
    } else {
        cout << "Nepal doesn't exists" << endl;
    }

    if(n.count("Canada")) {
        cout << "Canada exists" << endl;
    } else {
        cout << "Canada doesn't exists" << endl;
    }

    // Remove
    n.erase("Nepal");
    if(n.count("Nepal")) {
        cout << "Nepal exists" << endl;
    } else {
        cout << "Nepal doesn't exists" << endl;
    }

    // Update
    n["China"] = 200;
    cout << "Update value of China: " << n["China"] << endl;

    cout << "-------------------------------------" << endl;

    // Unordered Sets
    unordered_set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);
    s.insert(1); // duplicate value not inserted

    cout << "Size = " << s.size() << endl; // Size
    
    // Iteration
    cout << "Unordered Set: ";
    for(auto el:s) {
        cout << el << " ";
    }
    cout << endl;

    // Search
    if(s.find(3) != s.end()) {
        cout << "3 exists" << endl; 
    } else {
        cout << "3 doesn't exist " << endl;
    }
    if(s.find(10) != s.end()) {
        cout << "10 exists" << endl; 
    } else {
        cout << "10 doesn't exist " << endl;
    }

    // Remove
    s.erase(3);
    if(s.find(3) != s.end()) {
        cout << "3 exists" << endl; 
    } else {
        cout << "3 doesn't exist " << endl;
    }

    cout << "-------------------------------------" << endl;

    // Sets
    set<int> p;
    p.insert(1);
    p.insert(5);
    p.insert(3);
    p.insert(2);
    p.insert(1); // duplicate value not inserted

    cout << "Size = " << p.size() << endl; // Size
    
    // Iteration
    cout << "Set: ";
    for(auto el:p) {
        cout << el << " ";
    }
    cout << endl;

    // Search
    if(p.find(3) != p.end()) {
        cout << "3 exists" << endl; 
    } else {
        cout << "3 doesn't exist " << endl;
    }
    if(p.find(10) != p.end()) {
        cout << "10 exists" << endl; 
    } else {
        cout << "10 doesn't exist " << endl;
    }

    // Remove
    p.erase(3);
    if(p.find(3) != p.end()) {
        cout << "3 exists" << endl; 
    } else {
        cout << "3 doesn't exist " << endl;
    }
    
    cout << "-------------------------------------" << endl;

    // Pair Sum
    int arr[7] = {1, 2, 7, 11, 15, 5, 9};
    int q = 7;
    int target = 9;
    unordered_map<int, int> a; // key = arr[i], val = idx

    for(int i=0; i<q; i++) {
        int comp = target - arr[i];
        if(a.count(comp)) {
            cout << "ans = " << a[comp] << " , " << i << endl;
            break;
        } 
        a[arr[i]] = i;
    }

    
    return 0;
}