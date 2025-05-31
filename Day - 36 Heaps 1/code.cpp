#include <iostream>
#include <queue>
#include <string>
using namespace std;

// BUilding Heap
// Max Heap
class Heap {
    vector<int> vec; // CBT - Max Heap

public:

    // Push in Heap
    void push(int val) {
        
        // Step 1 - insert(val) - O(1)
        vec.push_back(val);

        // Step 2 - Fix Heap - O(logn)
        int x = vec.size()-1;
        int parIdx = (x-1)/2;

        while(parIdx >= 0 && vec[x] > vec[parIdx]) {
            swap(vec[x], vec[parIdx]);
            x = parIdx;
            parIdx = (x-1)/2;
        }
    }

    // Pop in Heap
    void heapify(int i) {
        if(i >= vec.size()) {
            return;
        }

        int l = 2*i + 1;
        int r = 2*i + 2;
        int maxIdx = i;
        
        if(l < vec.size() && vec[l] > vec[maxIdx]) {
            maxIdx = l;
        }
        
        if(r < vec.size() && vec[r] > vec[maxIdx]) {
            maxIdx = r;
        }

        swap(vec[i], vec[maxIdx]);
        
        if(maxIdx != i) { // Swapping with child node
            heapify(maxIdx);
        }
    }

    void pop() {
        // Step 1 - Swap root & lastIdx - O(1)
        swap(vec[0], vec[vec.size()-1]);
        
        // Step 2 - Delete last element - O(1)
        vec.pop_back();

        // Step 3 - Fix the Heap - O(logn)
        heapify(0);     
    }

    int top() {
        return vec[0]; // Highest Priority Element - Min
    }

    bool empty() {
        return vec.size() == 0;
    }
};

// Min Heap
class Heap2 {
    vector<int> vec; // CBT - Min Heap

public:

    void push(int val) {
        
        // Step 1 - insert(val) - O(1)
        vec.push_back(val);

        // Step 2 - Fix Heap - O(logn)
        int x = vec.size()-1;
        int parIdx = (x-1)/2;

        while(parIdx >= 0 && vec[x] < vec[parIdx]) {
            swap(vec[x], vec[parIdx]);
            x = parIdx;
            parIdx = (x-1)/2;
        }
    }

    void heapify(int i) {
        
        if(i >= vec.size()) {
            return;
        }

        int l = 2*i + 1;
        int r = 2*i + 2;
        int maxIdx = i;
        
        if(l < vec.size() && vec[l] < vec[maxIdx]) {
            maxIdx = l;
        }
        
        if(r < vec.size() && vec[r] < vec[maxIdx]) {
            maxIdx = r;
        }

        swap(vec[i], vec[maxIdx]);
        
        if(maxIdx != i) { // Swapping with child node
            heapify(maxIdx);
        }
    }

    void pop() {
        // Step 1 - Swap root & lastIdx - O(1)
        swap(vec[0], vec[vec.size()-1]);
        
        // Step 2 - Delete last element - O(1)
        vec.pop_back();

        // Step 3 - Fix the Heap - O(logn)
        heapify(0);     
    }

    int top() {
        return vec[0]; // Highest Priority Element - Min
    }

    bool empty() {
        return vec.size() == 0;
    }
};

// PQ for Objects
// Max Heap
class Student{
public:
    string name;
    int marks;
    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }
    bool operator < (const Student &obj) const {
        return this->marks < obj.marks;
    }
};
// Min Heap
class Student2{
public:
    string name;
    int rank;
    Student2(string name, int rank) {
        this->name = name;
        this->rank = rank;
    }
    bool operator < (const Student2 &obj) const {
        return this->rank > obj.rank;
    }
};

// PQ for Pairs
struct ComparePair{
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {
        // return p1.second < p2.second; // Max Heap
        return p1.second > p2.second; // Min Heap
    }
};

int main() {

    priority_queue<int> pq;
    pq.push(5);
    pq.push(3);
    pq.push(10);
    while(!pq.empty()) {
        cout << "top = " << pq.top() << endl;
        pq.pop();
    }

    cout << "---------------------------------------" << endl;

    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(5);
    pq2.push(3);
    pq2.push(10);
    while(!pq2.empty()) {
        cout << "top = " << pq2.top() << endl;
        pq2.pop();
    }

    cout << "---------------------------------------" << endl;

    priority_queue<string, vector<string>, greater<string>> pq3;
    pq3.push("helloworld");
    pq3.push("apnacollege");
    pq3.push("c++");
    while(!pq3.empty()) {
        cout << "top = " << pq3.top() << endl;
        pq3.pop();
    }

    cout << "---------------------------------------" << endl;

    // Building Heap
    Heap heap;
    Heap2 heap2;
    
    // Push in Heap
    heap.push(50);
    heap.push(30);
    heap.push(100);

    heap2.push(50);
    heap2.push(30);
    heap2.push(100);

    // Top in Heap
    cout << "top (Max Heap) = " << heap.top() << endl; // 100
    cout << "top (Min Heap) = " << heap2.top() << endl; // 30

    cout << "---------------------------------------" << endl;

    // Pop in Heap
    Heap h;
    Heap2 h2;

    h.push(9);
    h.push(4);
    h.push(8);
    h.push(1);
    h.push(2);
    h.push(5);

    h2.push(9);
    h2.push(4);
    h2.push(8);
    h2.push(1);
    h2.push(2);
    h2.push(5);

    cout << "Max Heap = ";
    while(!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }
    cout << endl;

    cout << "Min Heap = ";
    while(!h2.empty()) {
        cout << h2.top() << " ";
        h2.pop();
    }
    cout << endl;

    cout << "---------------------------------------" << endl;

    // PQ for Objects
    // Max Heap
    priority_queue<Student> pq4;
    pq4.push(Student("Aman", 85));
    pq4.push(Student("Ayush", 90));
    pq4.push(Student("Ankita", 80));

    while(!pq4.empty()) {
        cout << pq4.top().name << ", " << pq4.top().marks << endl;
        pq4.pop();
    }

    cout << "---------------------------------------" << endl;

    // Min Heap
    priority_queue<Student2> p;
    p.push(Student2("Aman", 3));
    p.push(Student2("Ayush", 1));
    p.push(Student2("Ankita", 5));

    while(!p.empty()) {
        cout << p.top().name << ", " << p.top().rank << endl;
        p.pop();
    }

    cout << "---------------------------------------" << endl;

    // PQ for Pairs
    // priority_queue<pair<string, int>> q; // default - Max Heap
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> q;
    q.push(make_pair("Aman", 500));
    q.push(make_pair("Bob", 1000));
    q.push(make_pair("Chetan", 1500));
    
    while(!q.empty()) {
        cout << q.top().first << ", " << q.top().second << endl;
        q.pop();
    }

    cout << "---------------------------------------" << endl;

    return 0;
}