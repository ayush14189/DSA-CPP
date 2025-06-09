#include <iostream>
using namespace std;

// Cheapest Flights within K Stops


// Disjoint Set
class DisjointSet{
public:
    int n;
    vector<int> par;
    vector<int> rank;

    DisjointSet(int n) {
        this->n = n;
        for(int i=0; i<n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        return find(par[x]);
    }
    int unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]) {
            
        }
    }
};

// Kruskal's Algorithm


// Flood Fill Agroithm


int main() {
    
    // Cheapest Flights within K Stops


    // Disjoint Set


    // Kruskal's Algorithm


    // Flood Fill Agroithm
    
    
    return 0;
}