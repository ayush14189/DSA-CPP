#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// Building Graph
// Unweighted Undirected
class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V]; 
    }

    void addEdge(int u, int v) { // u---v
        l[u].push_back(v);
        l[v].push_back(u);
    }
    
    void print() {
        for(int u=0; u<V; u++) { // 0 1 2 3 4
            list<int> neighbors = l[u];
            cout << u << ": ";
            for(int v : neighbors) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    
    // Breadth First Search - O(V + E)
    void bfs() {
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

        while(q.size() > 0) {
            int u = q.front(); // current vertex
            q.pop();
            cout << u << " ";
            
            list<int> neighbors = l[u]; // u ---- v
            for(int v : neighbors) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    // Depth First Search

};

// Weighted Undirected
class Graph2 {
    int V;
    list<pair<int, int>>* l;

public:
    Graph2(int V) {
        this->V = V;
        l = new list<pair<int, int>> [V]; 
    }

    void addEdge(int u, int v, int wt) { // u---v
        l[u].push_back(make_pair(v, wt));
        l[v].push_back(make_pair(u, wt));
    }
    
    // Print Graph
    void print() {
        for(int u=0; u<V; u++) { // 0 1 2 3 4
            list<pair<int, int>> neighbors = l[u];
            cout << u << ": ";
            for(pair<int, int> v : neighbors) {
                cout << "(" << v.first << "," << v.second << ")" << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    // Building Graph

    // Unweighted Undirected Graph
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(2, 4);

    graph.print();

    cout << "-------------------------------------" << endl;

    // Weighted Undirected Graph
    Graph2 graph2(5);

    graph2.addEdge(0, 1, 5);
    graph2.addEdge(1, 2, 1);
    graph2.addEdge(2, 3, 1);
    graph2.addEdge(3, 1, 3);
    graph2.addEdge(2, 4, 2);

    graph2.print();

    cout << "-------------------------------------" << endl;

    // Breadth First Search
    Graph g(8);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.bfs();

    cout << "-------------------------------------" << endl;

    // Depth First Search
    
    
    return 0;
}