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

// Height of Binary Tree
int height(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Kth level of Binary Tree
void KthHelper(Node*root, int K, int currLevel) {
    if(root == NULL) {
        return;
    }
    if(currLevel==K) {
        cout << root->data << " ";
        return;
    }
    KthHelper(root->left, K, currLevel+1);  // left
    KthHelper(root->right, K, currLevel+1); // right
}

void KthLevel(Node*root, int K) { // O(n)
    KthHelper(root, K, 1);
    cout << endl;
}

// Lowest Common Ancestor (LCA)

bool rootToNodePath(Node* root, int n, vector<int> &path) { // O(n)
    if(root == NULL) {
        return false;
    }
    path.push_back(root->data);
    if(root->data == n) {
        return true;
    }
    int isRight = rootToNodePath(root->left, n, path);
    int isLeft = rootToNodePath(root->right, n, path);
    if(isLeft || isRight) {
        return true;
    }
    path.pop_back();
    return false;
}

// Approach-1   O(n) ; O(n)
int LCA(Node* root, int n1, int n2) { 
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);
    
    int lca = -1;
    for(int i=0, j=0; i<path1.size() && j<path2.size(); i++, j++) {
        if(path1[i] != path2[j]) {
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

// Approach-2   O(n) ; O(1)
Node* LCA2(Node* root, int n1, int n2) {
    if(root == NULL) {
        return NULL;
    }
    
    if(root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);
    
    if(leftLCA != NULL && rightLCA != NULL) {
        return root;
    } 
    return leftLCA == NULL ? rightLCA : leftLCA;
}

// Min Distance between Nodes
int dist(Node* root, int n) {
    if(root == NULL) {
        return -1;
    } 
    if(root->data == n) {
        return 0;
    }
    int leftDist = dist(root->left, n);
    if(leftDist != -1) {
        return leftDist + 1;
    }
    int rightDist = dist(root->right, n);
    if(rightDist != -1) {
        return rightDist + 1;
    }
    return -1;
}

int minDist(Node*root, int n1, int n2) {
    Node* lca = LCA2(root, n1, n2);
    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);
    return (dist1 + dist2);
}

// Kth Ancestor of a Node - O(n)
int KthAncestor(Node* root, int node, int K) {
    if(root == NULL) {
        return -1;
    }
    if(root->data == node) {
        return 0;
    }
    int leftDist = KthAncestor(root->left, node, K);
    int rightDist = KthAncestor(root->right, node, K);
    if(leftDist == -1 && rightDist == -1) {
        return -1;
    }
    int validVal = leftDist == -1 ? rightDist : leftDist;
    if(validVal + 1 == K) {
        cout << K << "th Ancestor = " << root->data << endl;
    }
    return validVal+1;
}

// Transform to Sum Tree - O(n)
int transform (Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;
    root->data = leftOld + rightOld;
    if(root->left != NULL) {
        root->data += root->left->data;
    }
    if(root->right != NULL) {
        root->data += root->right->data;
    }
    return currOld;
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


int main() {
    vector<int> vec1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(vec1);

    // Kth Level of Binary Tree
    KthLevel(root, 2); // 2 3
    KthLevel(root, 3); // 4 5 6
    
    // Least Common Ancestor (LCA)
    cout << "LCA Approach-1" << endl;
    cout << LCA(root, 4, 5) << endl;
    cout << LCA(root, 4, 6) << endl;
    cout << LCA(root, 2, 6) << endl;

    cout << "LCA Approach-2" << endl;
    cout << LCA2(root, 4, 5)->data << endl;
    cout << LCA2(root, 4, 6)->data << endl;
    cout << LCA2(root, 2, 6)->data << endl;

    // Min Distance between Nodes
    cout << "Minimum Distance = " << minDist(root, 4, 6) << endl;
    cout << "Minimum Distance = " << minDist(root, 4, 5) << endl;
    cout << "Minimum Distance = " << minDist(root, 2, 6) << endl;

    // Kth Ancestor of a Node
    KthAncestor(root, 5, 2);
    KthAncestor(root, 6, 2);
    KthAncestor(root, 6, 1);

    // Transform to Sum Tree
    transform(root);
    levelOrder(root);

    return 0;
}