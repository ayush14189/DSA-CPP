#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Sorted Array to Balanced BST
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

Node* buildBSTFromSorted(int arr[], int st, int end) {
    if(st > end) {
        return NULL;
    }

    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = buildBSTFromSorted(arr, st, mid-1);
    curr->right = buildBSTFromSorted(arr, mid+1, end);

    return curr; 
}

// BST to Balanced BST
void getInorder(Node* root, vector<int> &nodes) {
    if(root == NULL) {
        return;
    }
    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}

Node* BSTFromSortedVec(vector<int> arr, int st, int end) {
    if(st > end) {
        return NULL;
    }

    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = BSTFromSortedVec(arr, st, mid-1);
    curr->right = BSTFromSortedVec(arr, mid+1, end);

    return curr; 
}

Node* balancedBST(Node* root) {
    if(root == NULL) {
        return NULL;
    }
    // Get Inorder Sequence
    vector<int> nodes;
    getInorder(root, nodes);

    // Inorder Sequence -> Balanced BST
    return BSTFromSortedVec(nodes, 0, nodes.size()-1);
}

// Largest BST in Binary Tree
class Info{
public:
    bool isBST;
    int min;
    int max;
    int size;

    Info(bool isBST, int min, int max, int size){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

static int maxSize; // ANSWER
static Node* largestRoot; // Another Question can be asked

Info* largestBST(Node* root) {
    // Base Case - 1 
    // if(root == NULL) {
    //     return new Info(true, INT_MAX, INT_MIN, 0);
    // }

    // Base Case - 2
    if(root == NULL) {
        return NULL;
    } 
    if(root->left == NULL && root->right == NULL) {
        return new Info(true, root->data, root->data, 1);
    }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));
    int currSize = leftInfo->size + rightInfo->size + 1;
    
    if(leftInfo->isBST && rightInfo->isBST 
        && root->data > leftInfo->max 
        && root->data < rightInfo->min) {
        maxSize = max(maxSize, currSize);
        largestRoot = root;
        return new Info(true, currMin, currMax, currSize);
    } 
    return new Info(false, currMin, currMax, currSize);
}

// Merge 2 BSTs
Node* mergeBST(Node* root1, Node* root2) {
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    // Inorder Sequences of BSTs
    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    // Merge Sequences
    int i=0, j=0;
    while(i<nodes1.size() && j<nodes2.size()) {
        if(nodes1[i] < nodes2[j]) {
            merged.push_back(nodes1[i++]);
        } else {
            merged.push_back(nodes2[j++]);
        }
    }

    while(i<nodes1.size()) {
        merged.push_back(nodes1[i++]);
    }

    while(j<nodes2.size()) {
        merged.push_back(nodes2[j++]);
    }

    return BSTFromSortedVec(merged, 0, merged.size()-1);
}

// Preorder Sequence - default
void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    // Sorted Array to Balanced BST
    int arr[7] = {3, 4, 5, 6, 7, 8, 9};
    Node* root1 = buildBSTFromSorted(arr, 0, 6);
    preorder(root1);
    cout << endl;

    cout << "-----------------------------------------------------" << endl;

    // BST to Balanced BST
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    
    cout << "Unbalanced BST = "; 
    preorder(root); 
    cout << endl;
    
    root = balancedBST(root);
    cout << "Balanced BST = "; 
    preorder(root); 
    cout << endl;

    cout << "-----------------------------------------------------" << endl;

    // Size of Largest BST in Binary Tree
    Node* root2 = new Node(50);
    root2->left = new Node(30);
    root2->left->left = new Node(5);
    root2->left->right = new Node(20);

    root2->right = new Node(60);
    root2->right->left = new Node(45);
    root2->right->right = new Node(70);
    root2->right->right->left = new Node(65);
    root2->right->right->right = new Node(80);

    largestBST(root2);
    cout << "Binary Tree = "; preorder(root2); cout << endl;
    cout << "MAX SIZE = " << maxSize << endl; // 5
    cout << "LARGEST ROOT = " << largestRoot->data << endl; // 60 - Another Question

    cout << "-----------------------------------------------------" << endl;

    // Merge 2 BSTs
    Node* root3 = new Node(2);
    root3->left = new Node(1);
    root3->right = new Node(4);
    cout << "BST 1 = "; preorder(root3); cout << endl;

    Node* root4 = new Node(9);
    root4->left = new Node(3);
    root4->right = new Node(12);
    cout << "BST 2 = "; preorder(root4); cout << endl;
    
    Node* root5 = mergeBST(root3, root4);
    cout << "Merged BST = " ; preorder(root5); cout << endl;
    
    return 0;
}