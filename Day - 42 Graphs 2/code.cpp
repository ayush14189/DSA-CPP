#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// Building Graph
class Graph {
    int V;
    list<int>* l;
    bool isUndir;

public:
    Graph(int V, bool isUndir=true) {
        this->V = V;
        l = new list<int> [V]; 
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v) { // u---v
        l[u].push_back(v);
        if(isUndir) { // false
            l[v].push_back(u);
        }    
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
            }
        }
}

    // Depth First Search - Disconnected Components
    void dfsHelper(int u, vector<bool> &vis) {
        cout << u << " ";
        vis[u] = true;
        list<int> neighbors = l[u];
        
        for(int v : neighbors) {
            if(!vis[v]) {
                dfsHelper(v, vis);
            }
        }
}

    void dfs() {
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfsHelper(i, vis); // starting pt = i
                cout << endl;
            }
        }
    }

    // Cycle in Graph - Undirected Graph
    bool undirCycleHelper(int src, int par, vector<bool> &vis) { // O(V + E)
        vis[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors) {
            if(!vis[v]) {
                if(undirCycleHelper(v, src, vis)) {
                    return true;
                }
            } else {
                if(v != par) { // Cycle Condition
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir() {
        vector<bool> vis(V, false);
        return undirCycleHelper(0, -1, vis);
    }

    // Cycle in Graph - Directed Graph
    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath) {
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors) {
            if(!vis[v]) {
                if(dirCycleHelper(v, vis, recPath)) {
                    return true;
                }
            } else {
                if(recPath[v]) {
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycleDir() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dirCycleHelper(i, vis, recPath)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isBipartite() {
        queue<int> q;
        vector<bool> vis(V, false);
        vector<int> color (V, -1);
        q.push(0);
        color[0] = 0;
        vis[0] = 0;

        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            list<int> neighbors = l[curr];

            for(int v : neighbors) {
                if(!vis[v]) {
                    vis[v] = true;
                    color[v] = !color[curr];
                    q.push(v);
                } else {
                    if(color[v] == color[curr]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    // Without vis[]
    bool isBipartite2() {
        queue<int> q;
        vector<int> color (V, -1);
        q.push(0);
        color[0] = 0;
        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            list<int> neighbors = l[curr];

            for(int v : neighbors) {
                if(color[v] == -1) { // unvisited
                    color[v] = !color[curr];
                    q.push(v);
                } else {
                    if(color[v] == color[curr]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    // All Paths Problem
    void pathHelper(int src, int dest, vector<bool> &vis, string &path) { // O(V + E)
        if(src == dest) {
            cout << path << dest << endl;
            return;
        }
        vis[src] = true;
        path += to_string(src);
        list<int> neighbors = l[src];

        for(int v : neighbors) {
            if(!vis[v]) {
                pathHelper(v, dest, vis, path);
            }
        }
        path = path.substr(0, path.size()-1);
        vis[src] = false;
    }

    void printAllPaths(int src, int dest) {
        vector<bool> vis(V, false);
        string path = "";
        pathHelper(src, dest, vis, path);
    }
};

int main() {

    Graph g(10, true);

    g.addEdge(1, 6);
    g.addEdge(6, 4);
    g.addEdge(4, 3);
    g.addEdge(4, 9);
    g.addEdge(3, 8);
    g.addEdge(3, 7);
    g.addEdge(2, 0);
    g.addEdge(2, 5);

    g.bfs(); // Breadth First Search - Disconnected Components

    cout << "-------------------------------------" << endl;

    g.dfs(); // Depth First Search - Disconnected Components

    cout << "-------------------------------------" << endl;
    
    // Cycle in Graph - Undirected Graph

    int V = 5; 
    Graph graph(V, true);

    graph.addEdge(0, 1);
    // graph.addEdge(0, 2); // Removing Cycle - 0
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);

    // 1 - true ; 0 - false (Removing Cycle)
    cout << graph.isCycleUndir() << endl;

    cout << "-------------------------------------" << endl;

    // Cycle in Graph - Directed Graph
    
    Graph gr(4, false);

    gr.addEdge(1, 0);
    gr.addEdge(0, 2);
    gr.addEdge(2, 3);
    // gr.addEdge(3, 0); // Removing Cycle

    // 1 - true ; 0 - false (Removing Cycle)
    cout << gr.isCycleDir() << endl;

    cout << "-------------------------------------" << endl;

    // Bipartite Graph

    Graph grp(4, true);

    grp.addEdge(0, 1);
    grp.addEdge(0, 2);
    grp.addEdge(1, 3);
    grp.addEdge(2, 3);
    cout << grp.isBipartite() << endl; // 1
    cout << grp.isBipartite2() << endl; // 1

    Graph grp2(5, true);

    grp2.addEdge(0, 1);
    grp2.addEdge(0, 2);
    grp2.addEdge(1, 3);
    grp2.addEdge(2, 4);
    grp2.addEdge(3, 4);

    cout << grp2.isBipartite() << endl; // 0
    cout << grp2.isBipartite2() << endl; // 0

    cout << "-------------------------------------" << endl;

    // All Paths Problem
    Graph grph(6, false);

    grph.addEdge(2, 3);
    grph.addEdge(3, 1);
    grph.addEdge(0, 3);
    grph.addEdge(4, 0);
    grph.addEdge(4, 1);
    grph.addEdge(5, 0);
    grph.addEdge(5, 2);

    grph.printAllPaths(5, 1);

    cout << "-------------------------------------" << endl;
    
    return 0;
}