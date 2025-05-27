#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>
using namespace std;
// Stack using Vector with class template
template<class T>
// Stack using Vector
class Stack {
    vector<T> vec;

public:
    void push(T val) { // O(1)
        vec.push_back(val);
    }
    void pop() {         // O(1)
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        vec.pop_back();
    }
    T top() {          // O(1)
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            int lastIdx = vec.size()-1;
            return vec[lastIdx];
        }
    }
    bool isEmpty() {
        return vec.size()==0;
    }
};

// Stack using LinkedList
template<class T>
class Stack2{
    list<T> ll;
public:
    void push(T val) {
        ll.push_front(val);
    }
    void pop() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        } else {
            ll.pop_front();
        }
    }
    T top() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            return ll.front();
        }
    }
    bool isEmpty() {
        return ll.size()==0;
    }
};

// Stack using LinkedList with Class Template
// Using STL
template<class T>
class Node{
public:
    T data;
    Node<T>* next;
    Node(T val) {
        data = val;
        next = NULL;
    }
};
// Using Manual LinkedList 
template<class T>
class Stack3{
    Node<T>* head;
public:
    Stack3() {
        head = NULL;
    }
    void push(T val) {
        // push_front
        Node<T>* newNode = new Node<T>(val);
        if(head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void pop() {
        // pop_front
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    T top() {
        return head->data;
    }
    bool isEmpty() {
        return head == NULL;
    }
};

// Push at Bottom of Stack
template<class T>
void pushAtBottom(stack<T>& s, T val) {
    if(s.empty()) {
        s.push(val);
        return;
    }
    T temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}

// Reverse a Stack
template<class T>
void reverse(stack<T> &s) {
    if(s.empty()) {
        return;
    }
    T temp = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s, temp);
}

// Reverse a String using Stack
void reverseString(string &str) {
    stack<char> s;
    int n = str.size();
    for(int i=0; i<n; i++) {
        s.push(str[i]);
    }
    for(int i=0; i<n; i++) {
        str[i] = s.top();
        s.pop();
    }

}
string reverseString2(string str) {
    stack<char> s;
    string ans;
    int n = str.size();
    for(int i=0; i<n; i++) {
        s.push(str[i]);
    }
    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }
    return ans;
}

// Print Stack
template <class T>
void printStack(stack<T> s){
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Stock Span
void stockSpan(vector<int> stock, vector<int> &span) {
    stack<int> s;
    s.push(0);
    span[0] = 1;
    for(int i=1; i<stock.size(); i++) {
        while(!s.empty() && stock[i] >= stock[s.top()]) {
            s.pop();
        }
        if(s.empty()) {
            span[i] = i+1;
        } else {
            int prevHigh = s.top();
            span[i] = i-prevHigh;
        }

    }
    for(int i=0; i<span.size(); i++) {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main() {
    
    Stack<int> s;   // int stack
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    Stack<char> q;  // char stack
    q.push('c');
    q.push('b');
    q.push('a');
    while(!q.isEmpty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;

    // Stack using Vector with Class Template
    Stack<string> r;
    r.push("Apple");
    r.push("Banana");
    r.push("Orange");
    while(!r.isEmpty()) {
        cout << r.top() << " ";
        r.pop();
    }
    cout << endl;

    // Stack using LinkedList with Class Template
    // Using STL
    Stack2<int> t;
    t.push(3);
    t.push(2);
    t.push(1);
    while(!t.isEmpty()) {
        cout << t.top() << " ";
        t.pop();
    }   
    cout << endl;

    // Using Manual LinkedList 
    Stack3<int> p;
    p.push(3);
    p.push(2);
    p.push(1);
    while(!p.isEmpty()) {
        cout << p.top() << " ";
        p.pop();
    } 
    cout << endl;

    // Stack in STL
    stack<int> a;
    a.push(3);
    a.push(2);
    a.push(1);
    while(!a.empty()) {
        cout << a.top() << " ";
        a.pop();
    } 
    cout << endl;

    // Push at Bottom of Stack
    stack<int> b;
    b.push(3);
    b.push(2);
    b.push(1);
    cout << "Before pushing at bottom: ";
    stack<int> temp = b; // Copy the stack to print it
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    pushAtBottom(b, 4);
    cout << "After pushing 4 at bottom: ";
    while(!b.empty()) {
        cout << b.top() << " ";
        b.pop();
    }
    cout << endl;

    // Reverse a Stack
    stack<int> c;
    c.push(3);
    c.push(2);
    c.push(1);
    cout << "Before reversal: ";
    printStack(c);
    reverse(c);
    cout << "After reversal: ";
    printStack(c);

    // Reverse a String using Stack
    string str = "abcd";
    reverseString(str); 
    cout << str << endl;
    string str2 = "abcd";
    cout << reverseString2(str2) << endl; 

    // Stock Span
    vector <int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0};
    stockSpan(stock, span);

    return 0;
}