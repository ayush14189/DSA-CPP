#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// Building Graph
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
    
    // Breadth First Search - Disconnected Componentss
    void bfsHelper(int st, vector<bool> &vis) {
        queue<int> q;
        q.push(st);
        vis[st] = true;

        while(q.size() > 0) {
            int u = q.front(); // current vertex
            q.pop();
            cout << u << " ";
            
            list<int> neighbors = l[u]; // u ---- v
            for(int v : neighbors) {
            // To ensure that one node is added only once to Queue
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void bfs() {
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                bfsHelper(i, vis);
                cout << endl;
            }
        }
    }

    // Depth First Search - Disconnected Components
    void dfsHelper(int u, vector<bool> &vis) {
        vis[u] = true;
        cout << u << " ";

        list<int> neighbors = l[u];
        for(int v : neighbors) {
            if(!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs() {
        vector<bool> vis(7, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfsHelper(i, vis); // starting pt = i
                cout << endl;
            }
        }
        cout << endl;
    }

    // Has Path Problem
    bool pathHelper(int src, int dest, vector<bool> &vis) {
        if(src == dest) {
            return true;
        }
        vis[src] = true;
        list<int> neighbors = l[src];
        for(int v : neighbors) {
            if(!vis[v]) {
                if(pathHelper(v, dest, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPath(int src, int dest) {
        vector<bool> vis(V, false);
        return pathHelper(src, dest, vis);
    }
};

int main() {

    // Breadth First Search - Disconnected Components
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

    // Depth First Search - Disconnected Components
    g.dfs();    

    cout << "-------------------------------------" << endl;

    cout << "-------------------------------------" << endl;
    
    return 0;
}