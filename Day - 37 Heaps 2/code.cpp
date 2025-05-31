#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Heap Sort
// Ascending Order
void heapify(int i, vector<int> &arr, int n) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxIdx = i;

    if(left < n && arr[left] > arr[maxIdx]) {
        maxIdx = left;
    } 
    if(right < n && arr[right] > arr[maxIdx]) {
        maxIdx = right;
    } 

    if(maxIdx != i) {
        swap(arr[i], arr[maxIdx]);
        heapify(maxIdx, arr, n);
    }
}
// Descending Order
void heapify2(int i, vector<int> &arr, int n) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int minIdx = i;

    if(left < n && arr[left] < arr[minIdx]) {
        minIdx = left;
    } 
    if(right < n && arr[right] < arr[minIdx]) {
        minIdx = right;
    } 

    if(minIdx != i) {
        swap(arr[i], arr[minIdx]);
        heapify2(minIdx, arr, n);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Step 1 - Build Max Heap - O(n*logn)
    for(int i=n/2; i>=0; i--) {
        heapify(i, arr, n);  // Ascending
        // heapify2(i, arr, n); // Descending
    }

    // Step 2 - Sorting - O(n*logn)
    for(int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(0, arr, i);  // Ascending
        // heapify2(0, arr, i); // Descending
    }
}

// Nearby Cars
class Car {
public:
    int idx;
    int distSq;

    Car(int idx, int disgtSq) {
        this->idx = idx;
        this->distSq = disgtSq;
    }

    bool operator < (const Car &obj) const {
        return this->distSq > obj.distSq;
    }
};

void nearbyCars(vector<pair<int, int>> pos, int K) {    // O(n + k*logn)
    vector<Car> cars;

    for(int i=0; i<pos.size(); i++) {                   // O(n)
        int distSq = pos[i].first * pos[i].first + pos[i].second * pos[i].second;
        cars.push_back(Car(i, distSq));
    }

    priority_queue<Car> pq(cars.begin(), cars.end());   // O(n)

    for(int i=0; i<K; i++) {                            // O(K*logn)
        cout << "Car = " << pq.top().idx << endl;
        pq.pop();
    }
}   

// Connect N Ropes
int connectNRopes(vector<int> ropes) {
    priority_queue<int, vector<int>, greater<int>> pq (ropes.begin(), ropes.end());
    
    int cost = 0;
    while(pq.size() > 1) {
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        cost += min1 + min2;
        pq.push(min1 + min2);
    } 
    cout << "Cost = " << cost << endl;
}

// Weakest Soldier
class Row{
public:
    int count;
    int idx;
    
    Row(int count, int idx) {
        this->count = count;
        this->idx = idx;
    }

    bool operator < (const Row &obj) const {
        if(this->count == obj.count) {
            return this->idx > obj.idx;
        }
        return this->count > obj.count; // Min Heap
    }
};

void weakestSoldier(vector<vector<int>> matrix, int K) {
    vector<Row> rows;
    for(int i=0; i<matrix.size(); i++) {
        int count = 0;
        for(int j=0; j<matrix[i].size() && matrix[i][j] == 1; j++) {
            count++;
        }
        rows.push_back(Row(count, i));
    }
    priority_queue<Row> pq(rows.begin(), rows.end());
    for(int i=0; i<K; i++) {
        cout << "Row: " << pq.top().idx << endl;
        pq.pop();
    }
}

// Sliding Window Maximum

void slidingWindow(vector<int> arr, int K) {
    // pq.top() -> sliding window -> pair(arr[i], i)
    priority_queue<pair<int, int>> pq;
    
    // 1st Window
    for(int i=0; i<K; i++) {
        pq.push(make_pair(arr[i], i));
    }

    cout << "Output: " << pq.top().first << " ";

    for(int i=K; i<arr.size(); i++) {
        while(!pq.empty() && pq.top().second <= (i-K)) { // Outside Window
            pq.pop();
        }
        pq.push(make_pair(arr[i], i));
        cout << pq.top().first << " ";
    }
    cout << endl;
}

int main() {
    // Heap Sort
    vector<int> arr = {1, 4, 2, 5, 3};
    heapSort(arr);
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "-------------------------------------" << endl;
    
    // Nearby Cars
    vector<pair<int, int>> pos;
    pos.push_back(make_pair(3, 3));
    pos.push_back(make_pair(5, -1));
    pos.push_back(make_pair(-2, 4));
    int K = 2;
    nearbyCars(pos, K);

    cout << "-------------------------------------" << endl;

    // Connect N Ropes 
    vector<int> ropes = {4, 3, 2, 6};
    connectNRopes(ropes);

    cout << "-------------------------------------" << endl;

    // Weakest Soldier
    vector<vector<int>> rows = {{1, 0, 0, 0},
                                {1, 1, 1, 1},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0}};
    cout << "K=2" << endl;
    weakestSoldier(rows, 2);
    cout << "K=3" << endl;
    weakestSoldier(rows, 3);

    cout << "-------------------------------------" << endl;

    // Sliding Window Maximum
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    slidingWindow(a, 3);
 
    cout << "-------------------------------------" << endl;
    
    return 0;
}