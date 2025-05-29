#include <iostream>
#include <vector>
using namespace std;

// Insert & Build a BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) { // O(logn)
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(val < root->data) {  // left subtree
        root->left = insert(root->left, val);
    } else {                // right subtree
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    for(int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search in BST
bool search(Node* root, int key) { // O(Height): avg => O(logn) worst => O(n)
    if(root == NULL) {
        return false;
    }
    if(root->data == key) {
        return true;
    }
    if(root->data > key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
} 

// Inorder Successor
Node* getInorderSuccessor(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a Node in BST
Node* delNode(Node* root, int val) {
    if(root == NULL) {
        return NULL;
    }
    if(val < root->data) {
        root->left = delNode(root->left, val);
    } else if(val > root->data) {
        root->right = delNode(root->right, val);
    } else {
        // root == val
        // Case 1 : 0 Children
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2 : 1 Child
        if(root->left == NULL || root->right == NULL) {
            return root->left == NULL ? root->right : root->left;
        }
        // Case 3 : 2 Children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data); // Case 1, Case 2
        return root;
    }
}

// Print in Range
void printInRange(Node* root, int start, int end) {
    if(root == NULL) {
        return;
    }
    if(start <= root->data && root->data <= end) { // Case 1
        printInRange(root->left, start, end);      // left subtree
        cout << root->data << " ";
        printInRange(root->right, start, end);     // right subtree
    } else if(root->data < start) {                // Case 2
        printInRange(root->right, start, end);     // right subtree
    } else {                                       // Case 3
        printInRange(root->left, start, end);      // left subtree
    }
}

// Root to Leaf Path
void printPath(vector<int> path) {
    cout << "path: ";
    for(int i=0; i<path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void pathHelper(Node* root, vector<int> &path) {
    if(root == NULL) {
        return;
    }

    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL) { // Leaf
        printPath(path);
        path.pop_back();
        return;
    }
    pathHelper(root->left, path);
    pathHelper(root->right, path);
    
    path.pop_back();
}

void rootToLeafPath(Node* root) {
    vector<int> path;
    pathHelper(root, path);
}

// Validate BST
bool validateHelper(Node* root, Node* min, Node* max) {
    if(root == NULL) {
        return true;
    }
    if(min != NULL && root->data < min->data) {
        return false;
    }
    if(max != NULL && root->data > max->data) {
        return false;
    }
    return validateHelper(root->left, min, root) 
        && validateHelper(root->right, root, max);
}

bool validateBST(Node* root) {
    return validateHelper(root, NULL, NULL);
}

int main() {
    // Insert & Build a BST
    
    int arr[6] = {5, 1, 3, 4, 2, 7};
    Node* root = buildBST(arr, 6); 
    inorder(root); cout << endl;

    int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root2 = buildBST(arr2, 9); 
    inorder(root2); cout << endl;

    // Search in BST
    cout << search(root, 2) << endl; // 1 - true
    cout << search(root, 6) << endl; // 0 - false
    cout << search(root2, 10) << endl; // 1 - true
    cout << search(root2, 2) << endl; // 0 - false
    
    // Delete a Node in BST
    inorder(root2);
    cout << endl;
    // delNode(root2, 4);  // Case 1
    // delNode(root2, 10); // Case 2
    // delNode(root2, 5);  // Case 3
    inorder(root2);
    cout << endl;
    
    // Print in Range
    printInRange(root2, 5, 12);
    cout << endl;
    
    // Root to Leaf Path
    rootToLeafPath(root2);
    
    // Validate BST

    cout << validateBST(root) << endl;  // 1 - true 
    cout << validateBST(root2) << endl; // 1 - true
    root2->data = 15;
    cout << validateBST(root2) << endl; // 0 - false
    
    return 0;
}