#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
    ~Node() {
        cout << "Node Destructor: " << data << endl;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
    }
};
class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }
    ~List() {
        cout << "List Destructor" << endl;
        if(head != NULL) {
            delete head;
            head = NULL;
        }
    }

    // Push Front
    void push_front(int val) {
        Node* newNode = new Node(val); // Dynamic Allocation
        // Node* newNode(val);         // Static Allocation
        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head; // newNode.next 
            head = newNode;
        }
    }

    // Push Back
    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print Linked List
    void printList() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Insert at a given position in the middle of Linked List
    void insert(int val, int pos) {
        Node* newNode = new Node(100);
        Node* temp = head;

        for(int i=0; i<pos-1; i++) {
            if(temp==NULL) {
                cout << "Position is Invalid" << endl;
                return;
            }
            temp = temp->next;
        }
        
        // temp is now at pos-1 (Left/Previous)
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Pop Front
    void pop_front() {
        if(head==NULL) {
            cout << "Linked List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    // Pop Back
    void pop_back() {
        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL; // temp = tail's prev
        delete tail;
        tail = temp; 
    }

    // Iterative Search on a Linked List
    int searchItr(int key) { // O(n)
        Node* temp = head;
        int idx = 0;
        while(temp != NULL) {
            if(temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // Recursive Search on a Linked List
    int helper(Node* head, int key) {
        if(head == NULL) {
            return -1;
        }
        if(head->data == key) {
            return 0;
        }
        int idx = helper(head->next, key);
        if(idx==-1) {
            return -1;
        }
        return idx+1;
    }
    int searchRec(int key) {
        return helper(head, key);
    }

    // Reverse a Linked List
    void reverse() {
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            // Updations for next iteration
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Find and Remove Nth Node from end
    int getSize() { // To get the size of Linked List
        int size=0;
        Node* temp = head;
        while(temp != NULL) {
            temp = temp->next;
            size++;
        }
        return size;
    }

    void removeNth(int n) { // TC = O(n) & SC = O(1)
        int size = getSize();
        Node* prev = head;
        for(int i=1; i<(size-n); i++) {
            prev = prev->next;
        }
        Node* toDelete = prev->next;
        cout << "Nth Node from end = " << toDelete->data << endl;
        prev->next = prev->next->next;
    }

};

int main() {
    // Linked List Implementation
    List ll; 

    // Push Front 
    // 1 -> 2 -> 3 -> NULL
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    
    // Push Back
    // 1 -> 2 -> 3 -> 4 -> NULL
    ll.push_back(4);
    
    // Print Linked List
    // 1 -> 2 -> 3 -> 4 -> NULL
    ll.printList(); 

    // Insert at a given position in the middle of Linked List
    // 1 -> 2 -> 100 -> 3 -> 4 -> NULL
    ll.insert(100, 2);
    ll.printList();

    // Pop Front
    // 2 -> 100 -> 3 -> 4 -> NULL
    ll.pop_front();
    ll.printList();

    // Pop Back
    // 2 -> 100 -> 3 -> NULL
    ll.pop_back();
    ll.printList();

    // Iterative Search on a Linked List
    List ll2;
    ll2.push_front(5);
    ll2.push_front(4);
    ll2.push_front(3);
    ll2.push_front(2);
    ll2.push_front(1);
    cout << "Iterative Search Result: " << ll2.searchItr(3) << endl;  // 2
    cout << "Iterative Search Result: " << ll2.searchItr(25) << endl; // -1

    // Recursive Search on a Linked List
    cout << "Recursive Search Result: " << ll2.searchRec(3) << endl;  // 2
    cout << "Recursive Search Result: " << ll2.searchRec(25) << endl; // -1

    // Reverse a Linked List
    ll2.reverse();
    ll2.printList();

    // Find and Remove Nth Node from end
    List ll3;
    ll3.push_front(5);
    ll3.push_front(4);
    ll3.push_front(3);
    ll3.push_front(2);
    ll3.push_front(1);
    ll3.removeNth(2);
    ll3.printList();

    return 0;
} 