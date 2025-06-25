#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    // Creating Segment Tree
    void buildTree(vector<int> &arr, int st, int end, int node) { // O(n) 
        if(st == end) {
            tree[node] = arr[st];
            return;
        }

        int mid = st + (end-st)/2;

        buildTree(arr, st, mid, 2*node+1);      // left
        buildTree(arr, mid+1, end, 2*node+2);   // right
        
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    // Queries on Segment Tree
    int rangeSum(int qi, int qj, int si, int sj, int node) { // O(logn)
        if(qj < si || qi > sj) {            // No Overlap
            return 0;
        } 
        
        if(si >= qi && sj <= qj) {   // Complete Overlap
            return tree[node];
        }
        
        // Partial Overlap
        int mid = si + (sj-si)/2;
        
        return rangeSum(qi, qj, si, mid, 2*node + 1)
               + rangeSum(qi, qj, mid+1, sj, 2*node + 2);
    }

    // Update on Segment Tree
    void updateUtil(int idx, int newVal, int st, int end, int node) { // O(logn)
        if(st == end) {
            tree[node] = newVal;
            return;
        }

        int mid = st + (end-st)/2;
        
        if(st <= idx && idx <= mid) {    // Left
            updateUtil(idx, newVal, st, mid, 2*node+1);
        } else {                        // Right
            updateUtil(idx, newVal, mid+1, end, 2*node+2);
        }
        
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }

public:
    SegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.resize(4*n);
        buildTree(arr, 0, n-1, 0);
    }

    void printTree() {
        for(int i=0; i<tree.size(); i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    int rangeQuery(int qi, int qj) {
        rangeSum(qi, qj, 0, n-1, 0);
    }

    void updateQuery(int idx, int newVal) {
        updateUtil(idx, newVal, 0, n-1, 0);
    }
};


// Range Max Segment Tree
class SegmentTree2 {
    vector<int> tree;
    int n;
    
    // Creation
    void buildTree(vector<int> nums, int st, int end, int node) { // O(n)
        if(st == end) {
            tree[node] = nums[st];
            return;
        }
        
        int mid = st + (end-st)/2;

        buildTree(nums, st, mid, 2*node+1);
        buildTree(nums, mid+1, end, 2*node+2);

        tree[node] = max(tree[2*node+1],tree[2*node+2]);
    }

    // Query
    int maxQuery(int qi, int qj, int si, int sj, int node) { // O(logn)
        
        if(qi > sj || qj < si) { // No Overlap
            return INT_MIN;
        }

        if(si >= qi && sj <= qj) { // Complete Overlap
            return tree[node];
        }

        // Partial Overlap
        int mid = si + (sj-si)/2;

        int leftMax = maxQuery(qi, qj, si, mid, 2*node+1);
        int rightMax = maxQuery(qi, qj, mid+1, sj, 2*node+2);

        return max(leftMax, rightMax);
    }

    // Update
    void updateUtil(int idx, int newVal, int st, int end, int node) {
        if(st == end) {
            tree[node] = newVal;
            return;
        }
        
        int mid = st + (end-st)/2;

        if(idx >= st && idx <= mid) {   // Left
            updateUtil(idx, newVal, st, mid, 2*node+1);
        } else {                        // Right
            updateUtil(idx, newVal, mid+1, end, 2*node+2);
        }

        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

public:

    SegmentTree2(vector<int> &nums) {
        n = nums.size();
        tree.resize(4 * n);
        buildTree(nums, 0, n-1, 0);
    }
    
    void printTree() {
        for(int i=0; i<tree.size(); i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    int rangeQuery(int qi, int qj) {
        maxQuery(qi, qj, 0, n-1, 0);
    }

    void updateQuery(int idx, int newVal) {
        updateUtil(idx, newVal, 0, n-1, 0);
    }
};

// Range Min Segment Tree
class SegmentTree3 {
    vector<int> tree;
    int n;
    
    // Creation
    void buildTree(vector<int> nums, int st, int end, int node) { // O(n)
        if(st == end) {
            tree[node] = nums[st];
            return;
        }
        
        int mid = st + (end-st)/2;

        buildTree(nums, st, mid, 2*node+1);
        buildTree(nums, mid+1, end, 2*node+2);

        tree[node] = min(tree[2*node+1],tree[2*node+2]);
    }

    // Query
    int minQuery(int qi, int qj, int si, int sj, int node) { // O(logn)
        
        if(qi > sj || qj < si) { // No Overlap
            return INT_MAX;
        }

        if(si >= qi && sj <= qj) { // Complete Overlap
            return tree[node];
        }

        // Partial Overlap
        int mid = si + (sj-si)/2;

        int leftMax = minQuery(qi, qj, si, mid, 2*node+1);
        int rightMax = minQuery(qi, qj, mid+1, sj, 2*node+2);

        return min(leftMax, rightMax);
    }

    // Update
    void updateUtil(int idx, int newVal, int st, int end, int node) {
        if(st == end) {
            tree[node] = newVal;
            return;
        }
        
        int mid = st + (end-st)/2;

        if(idx >= st && idx <= mid) {   // Left
            updateUtil(idx, newVal, st, mid, 2*node+1);
        } else {                        // Right
            updateUtil(idx, newVal, mid+1, end, 2*node+2);
        }

        tree[node] = min(tree[2*node+1], tree[2*node+2]);
    }

public:

    SegmentTree3(vector<int> &nums) {
        n = nums.size();
        tree.resize(4 * n);
        buildTree(nums, 0, n-1, 0);
    }
    
    void printTree() {
        for(int i=0; i<tree.size(); i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    int rangeQuery(int qi, int qj) {
        minQuery(qi, qj, 0, n-1, 0);
    }

    void updateQuery(int idx, int newVal) {
        updateUtil(idx, newVal, 0, n-1, 0);
    }
};

int main() {
    
    // Creating Segment Tree
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree st(arr);
    st.printTree();

    cout << "--------------------------------------------------------" << endl;

    // Queries on Segment Tree
    cout << st.rangeQuery(2, 5) << endl; // 18
    cout << st.rangeQuery(0, 3) << endl; // 10
    cout << st.rangeQuery(6, 7) << endl; // 15

    cout << "--------------------------------------------------------" << endl;
    
    // Update on Segment Tree
    st.updateQuery(1, 3);
    st.printTree();
    cout << st.rangeQuery(0, 3) << endl; // 11
    
    cout << "--------------------------------------------------------" << endl;

    // Range Max Segment Tree

    // 1. Creation
    vector<int> nums = {6, 8, -1, 2, 17, 1, 3, 2, 4};
    SegmentTree2 s(nums);
    s.printTree();

    cout << "--------------------------------------------------------" << endl;
    
    // 2. Query
    cout << s.rangeQuery(2, 5) << endl; // 17
    cout << s.rangeQuery(5, 8) << endl; // 4
    
    cout << "--------------------------------------------------------" << endl;

    // 3. Update
    s.updateQuery(4, 5);
    cout << s.rangeQuery(0, 8) << endl; // 8

    cout << "--------------------------------------------------------" << endl;
    
    // Range Min Segment Tree 

    // 1. Creation
    vector<int> num = {6, 8, -1, 2, 17, 1, 3, 2, 4};
    SegmentTree3 t(num);
    t.printTree();

    cout << "--------------------------------------------------------" << endl;
    
    // 2. Query
    cout << t.rangeQuery(2, 5) << endl; // -1
    cout << t.rangeQuery(5, 8) << endl; // 1
    
    cout << "--------------------------------------------------------" << endl;

    // 3. Update
    t.updateQuery(4, 5);
    cout << t.rangeQuery(0, 8) << endl; // -1

    cout << "--------------------------------------------------------" << endl;

    return 0;
}