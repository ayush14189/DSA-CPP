#include <iostream>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

// Queue Implementation using Linked List
class Node{
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
class Queue{
    Node* head;
    Node* tail;
public:
    Queue() {
        head = tail = NULL;
    }
    void push(int data) {   // push_back
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop() {            // pop_front
        if(empty()) {
            cout << "Empty queue" << endl;\
            return;
        }
            Node* temp = head;
            head = head->next;
            delete temp;
    }
    int front() {
        if(empty()) {
            cout << "Empty queue" << endl;\
            return -1;
        }
        return head->data;
    }
    bool empty() {
        return head == NULL;
    }

};

// Circular Queue using Array
class Queue2{
    int* arr;
    int capacity;
    int currSize;
    int f, r;

public:
    Queue2(int capacity) {
        this->capacity = capacity;
        arr = new int(capacity);
        currSize = 0;
        f = 0;
        r = -1;
    }
    void push(int data) {   // O(1)
        if(currSize == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        r = (r+1) % capacity;
        arr[r] = data;
        currSize++;
    } 
    void pop() {            // O(1)
        if(empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        f = (f+1) % capacity;
        currSize--;
    }
    int front() {           // O(1)
        if(empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[f];
    }
    bool empty() {
        return currSize == 0;
    }
    void printRear() {
        cout << arr[r] << endl;
    }
};

// Queue using 2 Stacks
class Queue3 {
    stack<int> s1;
    stack<int> s2;
public:
    void push(int data) { // O(n)
        // s1 -> s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // s1.push(data)
        s1.push(data);
        // s2 -> s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

    }
    void pop() {          // O(1)
        s1.pop();
    }
    int front() {         // O(1)
        return s1.top();
    }
    bool empty() {
        return s1.empty();
    }
};

// Stack using 2 Queues
class Stack{
    queue<int> q1;
    queue<int> q2;
public:
    void push(int data) { // O(n)
        // q1 -> q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // q1.push(data)
        q1.push(data);
        // q2 -> q1
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop() {          // O(1)
        q1.pop();
    }
    int top() {           // O(1)
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
};


// First Non-Repeating Letter
void firstNonRepeat(string str) {
    queue<char> q;
    int freq[26] = {0};

    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        q.push(ch);
        freq[ch-'a']++;
        
        while(!q.empty() && freq[q.front()-'a']>1) {
            q.pop();
        }
        
        if(q.empty()) {
            cout << "-1" << endl;
        } else{ 
            cout << q.front() << endl;
        }
    }
}
// Interleave 2 Queues
void interleave(queue<int> &org) {
    queue<int> f;
    int n = org.size();
    for(int i=0; i<n/2; i++) {
        f.push(org.front());
        org.pop();
    }
    while(!f.empty()) {
        org.push(f.front());
        f.pop();
        org.push(org.front());
        org.pop();
    }
}

// Queue Reversal
void reversal(queue<int> &q) {
    stack<int> s;
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

// Queue using Dequeue

// Stack using Dequeue
class Queue4{
    deque<int> deq;
public:
    void push(int data) {
        deq.push_back(data);
    }
    void pop() {
        deq.pop_front();
    } 
    int front() {
        return deq.front();
    }
    bool empty() {
        return deq.empty();
    }
};
class Stack2{
    deque<int> deq;
public:
    void push(int data) {
        deq.push_back(data);
    }
    void pop() {
        deq.pop_back();
    } 
    int top() {
        return deq.back();
    }
    bool empty() {
        return deq.empty();
    }
};

int main() {
    // Queue Implementation using Linked List
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    // Circular Queue using Array
    Queue2 a(4);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);


    cout << a.front() << endl;
    a.pop();
    cout << a.front() << endl;
    a.push(5);
    cout << a.front() << endl;
    a.printRear();

    // Queue in STL
    queue<int> p;
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);
    while(!p.empty()) {
        cout << p.front() << " ";
        p.pop();
    }
    cout << endl;

    // Queue using 2 Stacks
    Queue3 b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    while(!b.empty()) {
        cout << b.front() << " ";
        b.pop();
    }
    cout << endl;   

    // Stack using 2 Queues
    Stack c;
    c.push(1);
    c.push(2);
    c.push(3);
    c.push(4);
    while(!c.empty()) {
        cout << c.top() << " ";
        c.pop();
    }
    cout << endl;   

    // First Non-Repeating Letter
    string s = "aabccxb";
    firstNonRepeat(s);
    
    // Interleave 2 Queues
    queue<int> org;
    for(int i=1; i<=10; i++) {
        org.push(i);
    }
    interleave(org);
    for(int i=1; i<=10; i++) {
        cout << org.front() << " ";
        org.pop();
    }
    cout << endl;

    // Queue Reversal
    queue<int> z;
    z.push(1);
    z.push(2);
    z.push(3);
    z.push(4);
    z.push(5);
    reversal(z);
    while(!z.empty()) {
        cout << z.front() << " ";
        z.pop();
    }
    cout << endl;

    // Double Ended Queue (Deque)
    deque<int> deq;
    deq.push_front(2);
    deq.push_front(1);

    deq.push_back(3);
    deq.push_back(4);
    // 1 2 3 4
    deq.pop_front();
    deq.pop_back();
    // 2 3
    cout << "Front = " << deq.front() << endl; // 2
    cout << "Back = " << deq.back() << endl;   // 3

    // Queue using Deque
    Queue4 x;
    x.push(1);
    x.push(2);
    x.push(3);
    x.push(4);
    x.push(5);
    while(!x.empty()) {
        cout << x.front() << " ";
        x.pop();
    }
    cout << endl;

    // Stack using Deque
    Stack2 y;
    y.push(1);
    y.push(2);
    y.push(3);
    y.push(4);
    y.push(5);
    while(!y.empty()) {
        cout << y.top() << " ";
        y.pop();
    }
    cout << endl;

    return 0;
}