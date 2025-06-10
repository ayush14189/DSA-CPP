#include <iostream>
#include <vector>
#include <algorithm>
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
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]); // Path Compression
    }

    void unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        } else if(rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }

    void getInfo() {
        for(int i=0; i<n; i++) {
            cout << i << ": " << par[i] << " , " << rank[i] << endl;
        }
    }
};

// Kruskal's Algorithm
class Edge {
public:
    int u, v, wt;

    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph {
public:
    vector<Edge> edges;
    int V;
    vector<int> par;
    vector<int> rank;

    Graph(int V) {
        this->V = V;

        for(int i=0; i<V; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unionByRank(int u, int v) {
        int parU = find(u);
        int parV = find(v);

        if(rank[parU] == rank[parV]) {
            par[parV] = parU;
            rank[parU]++;
        } else if(rank[parU] > rank[parV]) {
            par[parV] = parU;
        } else {
            par[parU] = parV;
        }
    }

    void addEdge(int u, int v, int wt) {
        edges.push_back(Edge(u, v, wt));
    }

    void kruskals() { // O(ElogE)
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.wt < b.wt;});
        int minCost = 0;
        int count = 0;

        for(int i=0; i<edges.size() && count < V-1; i++) {
            Edge e = edges[i];
            int parU = find(e.u);
            int parV = find(e.v);
            if(parU != parV) { // No Cycle Edge
                unionByRank(parU, parV);
                minCost += e.wt;
                count++;
            }
        }

        cout << "Min Cost = " << minCost << endl;
    }
};

// Flood Fill Agorithm
void dfs(int row, int col, int n, int m, vector<vector<int>>& image, vector<vector<bool>>& vis, int newColor, int oldColor) {
    vis[row][col] = true;
    image[row][col] = newColor;

    // Up
    if(row-1 >= 0 && !vis[row-1][col] && image[row-1][col] == oldColor) {
        dfs(row-1, col, n, m, image, vis, newColor, oldColor);
    }   

    // Down
    if(row+1 < n && !vis[row+1][col] && image[row+1][col] == oldColor) {
        dfs(row+1, col, n, m, image, vis, newColor, oldColor);
    }        

    // Left
    if(col-1 >= 0 && !vis[row][col-1] && image[row][col-1] == oldColor) {
        dfs(row, col-1, n, m, image, vis, newColor, oldColor);
    }   

    // Right
    if(col+1 < m && !vis[row][col+1] && image[row][col+1] == oldColor) {
        dfs(row, col+1, n, m, image, vis, newColor, oldColor);
    }   
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n = image.size();
    int m = image[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    dfs(sr, sc, n, m, image, vis, newColor, image[sr][sc]);
    return image;
}


int main() {
    
    // Cheapest Flights within K Stops


    // Disjoint Set

    DisjointSet dj(6);
    dj.unionByRank(0, 2);
    cout << dj.find(2) << endl; // 0
    dj.unionByRank(1, 3);
    dj.unionByRank(2, 5);
    dj.unionByRank(0, 3);
    cout << dj.find(2) << endl; // 0
    dj.unionByRank(0, 4);

    dj.getInfo();

    cout << "-----------------------------------------------" << endl;

    // Kruskal's Algorithm

    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.kruskals();

    cout << "-----------------------------------------------" << endl;

    // Flood Fill Agroithm
    // LeetCode 733
    
    cout << "-----------------------------------------------" << endl;
    
    return 0;
}