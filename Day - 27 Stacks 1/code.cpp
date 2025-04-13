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

int main() {
    
    Stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    Stack<char> q;
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


    // Reverse a String using Stack
    // Reverse a Stack
    // Stock Span

    return 0;
}