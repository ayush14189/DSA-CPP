#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

// Build a Binary Tree from Preorder Sequence
Node* buildTree(vector<int> preorder) {
    idx++;
    if(preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);   // LEFT
    root->right = buildTree(preorder);  // RIGHT
    return root;
}

// Height of Binary Tree
int height(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Diameter of Binary Tree
// Approach 1 - O(n^2)
int diam1(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);
    return max(currDiam, max(leftDiam, rightDiam));
}

// Approach 2 - O(n)
pair<int, int> diam2(Node* root) {
    if(root == NULL) {
        return make_pair(0, 0);
    }
    // (diameter, height)
    pair<int, int> leftInfo = diam2(root->left);    // (LD, LH)
    pair<int, int> rightInfo = diam2(root->right);  // (RD, RH)
    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second)+1;
    return make_pair(finalDiam, finalHt);
}

// Subtree of another Tree
bool isIdentical(Node* root1, Node* root2) {
    
    if(root1==NULL && root2==NULL){
        return true;
    }
    
    if(root1==NULL || root2==NULL) {
        return false;
    }

    if(root1->data != root2->data) {
        return false;
    }
    
    return isIdentical(root1->left, root2->left) 
           && isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subRoot) {
    if(root==NULL && subRoot==NULL) {
        return true;
    }
    if(root==NULL || subRoot==NULL) {
        return false;
    }
    if(root->data == subRoot->data) {
        // Identical for Subtrees
        if (isIdentical(root, subRoot)) {
            return true;
        }
    }

    int isLeftSubtree = isSubtree(root->left, subRoot);
    
    if(!isLeftSubtree) {
        return isSubtree(root->right, subRoot);
    }
    return true;
}

// Top View of Tree
void topView(Node* root) {
    queue<pair<Node*,int>> q;  // (Node, HD)
    map<int, int> m;           // (HD, Node)
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        q.push(make_pair(root->left, -1));
        q.push(make_pair(root->right, 1));
        pair<Node*, int> curr = q.front();
        q.pop();
        Node* currNode = curr.first;
        int currHD = curr.second;
        if(m.count(currHD)==0) {

        }
    }
}

int main() {
    vector<int> vec1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(vec1);

    // Diameter of a Binary Tree
    cout << "Diameter = " << diam1(root) << endl;
    cout << "Diameter = " << diam2(root).first << endl;
    
    // Subtree of another Tree
    // true - 1
    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);
    cout << isSubtree(root, subRoot) << endl;

    // false - 0
    Node* subRoot2 = new Node(2);
    subRoot2->left = new Node(4);
    subRoot2->right = new Node(3);
    cout << isSubtree(root, subRoot2) << endl;

    // Maps in C++
    map<int, string> m;     // Creating a map
    
    m[101] = "Rajat";       // Insert in a map
    m[102] = "Adam";
    m[103] = "Rajat";
    
    cout << m[101] << endl; // Access value using key
    
    cout << m.count(102) << endl;           // 1 - Key is present
    cout << m.count(108) << endl;           // 0 - Key is not present
    
    m[101] = "Rahul";       // Update value using key
    cout << m[101] << endl;

    // Loop on map
    for(auto it:m) {
        cout << "Key = " << it.first << " Value = " << it.second << endl;
    }
    for(auto it:m) {
        cout << "double = " << it.first * 2 << endl;
    }

    // Top View of Tree
        
    
    return 0;
}