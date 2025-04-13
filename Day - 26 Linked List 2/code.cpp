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
    ~Node() { // Dynamic Deallocation
        if(next != NULL) {
            delete next;
            next = NULL;
        }
    }
};
class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }
    ~List() { // Dynamic Deallocation
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

    // Print Linked List
    void printList() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void printList(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
}

// Detect a Cycle in Linked List
bool isCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow) {
            cout << "Cycle exists" << endl;
            return true;
        }
    }
    cout << "Cycle doesn't exists" << endl;
    return false;
}

// Removing Cycle in Linked List
void removeCycle(Node* head) {
    
    // Detect Cycle
    bool isCycle= false;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow) {
            isCycle = true;
            break;
        }
    }
    if(!isCycle) {
        return;
    }

    slow = head;
    if(slow == fast) { // Special Case (tail -> head)
        while(fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL; // Remove Cycle
    } else {
        Node* prev = fast;
        while(slow!=fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL; // Remove Cycle
    }
}

Node* splitAtMid(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev != NULL) {
        prev->next = NULL;  // Split at Middle
    }
    return slow;            // slow = rightHead
}

Node* merge(Node* left, Node* right) {
    List ans;
    Node* i = left;
    Node* j = right;
    while(i != NULL && j != NULL) {
        if(i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;    
        }
    }
    while(i!=NULL) {
        ans.push_back(i->data);
        i = i->next; 
    }
    while(j!=NULL) {
        ans.push_back(j->data);
        j = j->next;  
    }
    return ans.head;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* rightHead = splitAtMid(head);
    Node* left = mergeSort(head);       // Left Head
    Node* right = mergeSort(rightHead); // Right Head
    return merge(left, right);          // Head of sorted LL
}

// Reverse a Linked List
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // prev is head of reversed LL
}

// Zig-Zag Linked List
Node* zigZagLL(Node* head) {
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    // Alternate Merging
    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = right;

    while(left!=NULL && right!=NULL) {
        Node* nextLeft = left->next;
        Node* nextRight = right->next;
        
        left->next = right;
        right->next = nextLeft;

        tail = right;
        
        left = nextLeft;
        right = nextRight;
    }
    if(right!=NULL) {
        tail->next = right;
    }
    return head;
}

int main() {

    // Detect Cycle in Linked List
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next = ll.head;
    // 1 -> 2 -> 3 -> 4 -> 1
    isCycle(ll.head); // Cycle exists

    // Remove Cycle in Linked List
    removeCycle(ll.head);
    ll.printList();

    // Merge Sort on Linked List
    List ll2;
    ll2.push_front(1);
    ll2.push_front(2);
    ll2.push_front(3);
    ll2.push_front(4);
    ll2.push_front(5);
    // printList(ll2.head);
    // ll2.head = mergeSort(ll2.head);
    // printList(ll2.head);

    // Zig-Zag Linked List
    List ll3;
    ll3.push_front(5);
    ll3.push_front(4);
    ll3.push_front(3);
    ll3.push_front(2);
    ll3.push_front(1);
    ll3.head = zigZagLL(ll3.head);
    printList(ll3.head);

    return 0;
}