#include <iostream>
#include <queue>
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

// Queue using 2 Stacks
// Stack using 2 Queues
// First Non-Repeating Letter
// Interleave 2 Queues
// Queue Reversal
// Double Ended Queue
// Queue using Dequeue
// Stack using Dequeue

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
    // Stack using 2 Queues
    // First Non-Repeating Letter
    // Interleave 2 Queues
    // Queue Reversal
    // Double Ended Queue
    // Queue using Dequeue
    // Stack using Dequeue
    return 0;
}