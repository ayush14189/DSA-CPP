#include <iostream>
#include <vector>
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

// Preorder Traversal - O(n)
void preOrder(Node* root) {
    if(root==NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Inorder Traversal - O(n)
void inOrder(Node* root) {
    if(root==NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Postorder Traversal - O(n)
void postOrder(Node* root) {
    if(root==NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Level Order Traversal
void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left != NULL) {
            q.push(curr->left);
        };
        if(curr->right != NULL) {
            q.push(curr->right);
        };
    }  
    cout << endl; 
}

void levelOrder2(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();

        // Variation using NULL
        if(curr == NULL) {
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }
        
        cout << curr->data << " ";
        if(curr->left != NULL) {
            q.push(curr->left);
        };
        if(curr->right != NULL) {
            q.push(curr->right);
        };
    }  
    cout << endl; 
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


// Count of Nodes
int count(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftCount = count(root->left);
    int rightCount = count (root->right);
    return leftCount + rightCount + 1;
}

// Sum of Nodes
int sum(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum (root->right);
    return leftSum + rightSum + root->data;
}


int main() {

    // Build a Binary Tree from Preorder Sequence
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    cout << root->data << " ";
    cout << root->left->data << " ";
    cout << root->right->data << " ";
    cout << root->right->left->data << " ";
    cout << root->right->right->data << endl;

    // Preorder Traversal
    cout << "Preorder Traversal" << endl;
    preOrder(root);
    cout << endl;

    // Inorder Traversal
    cout << "Inorder Traversal" << endl;
    inOrder(root);
    cout << endl;

    // Postorder Traversal
    cout << "Postorder Traversal" << endl;
    postOrder(root);
    cout << endl;

    // Level Order Traversal
    cout << "Level Order Traversal" << endl;
    levelOrder(root);
    cout << "Level Order Traversal with NULL" << endl;
    levelOrder2(root);

    // Height of Binary Tree
    cout << "Height = " << height(root) << endl;

    // Count of Nodes
    cout << "Number of Nodes = " << count(root) << endl;

    // Sum of Nodes
    cout << "Sum of Nodes = " << sum(root) << endl;

    return 0;
}