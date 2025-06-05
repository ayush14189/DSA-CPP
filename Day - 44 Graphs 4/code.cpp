#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

// Dijkstra's Algorithm

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};  

void dijkstra(int src, vector<vector<Edge>> graph, int V) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min Heap
    // pair(dist[v], v)
    vector<int> dist(V, INT_MAX);
    
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(pq.size() > 0) {
        int u = pq.top().second;
        pq.pop();

        vector<Edge> edges = graph[u];
        for(Edge e : edges) {
            if(dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }

    for(int d : dist) {
        cout << d << " ";
    }
    cout << endl;
}

// Bellman Ford Algorithm
void bellmanFord(vector<vector<Edge>> graph, int V, int src) { // O(V*E)
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i=0; i<V-1; i++) { // O(V)
        for(int u=0; u<V; u++) { // O(E)
            for(Edge e : graph[u]) {
                if(dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }
    for(int i=0; i<V; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

// Prim's Algorithm (MST)

class Graph {
    int V;
    list<pair<int, int>>* l; // int, int : neighbor, wt
    bool isUndir;

public:
    Graph(int V, bool isUndir = true) {
        this->V = V;
        l = new list<pair<int, int>> [V];
        this->isUndir = isUndir; 
    }

    void addEdge(int u, int v, int wt) { // u---v (weight)
        l[u].push_back(make_pair(v, wt));
        if(isUndir) {
            l[u].push_back(make_pair(u, wt));
        }
    }

    // Prim's Algorithm
    void primsAlgo(int src) {
        // minHeap -> (wt, v)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> mst(V, false);

        pq.push(make_pair(0, src));
        int ans = 0;

        while(pq.size() > 0) {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(!mst[u]) {
                mst[u] = true;
                ans += wt;
                list<pair<int, int>> neighbors = l[u];
                for(pair<int, int> n : neighbors) {
                    int v = n.first;
                    int currWt = n.second;
                    pq.push(make_pair(currWt, v));
                }
            }
        }
        cout << "Final Cost of MST = " << ans << endl;
    }
};

int main() {

    // Dijkstra's Algorithm

    int V = 6;
    vector<vector<Edge>> graph(V);
 
    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));
    
    graph[2].push_back(Edge(4, 3));
    
    graph[3].push_back(Edge(5, 1));
    
    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(2, 5));

    cout << "Shortest Paths:" << endl;
    dijkstra(0, graph, V);    
    dijkstra(1, graph, V);    

    cout << "-----------------------------" << endl;

    // Bellman Ford Algorithm

    int Ver = 5;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, -4));
    
    g[2].push_back(Edge(3, 2));
    
    g[3].push_back(Edge(4, 4));
    
    g[4].push_back(Edge(1, -1));

    cout << "Shortest Paths:" << endl;
    bellmanFord(g, Ver, 0);
    
    cout << "-----------------------------" << endl;
    
    // Prim's Algorithm (MST)

    Graph gr(4);

    gr.addEdge(0, 1, 10);
    gr.addEdge(0, 2, 15);
    gr.addEdge(0, 3, 30);

    gr.addEdge(1, 3, 30);
    
    gr.addEdge(1, 3, 40);
    
    gr.addEdge(0, 1, 10);
    gr.addEdge(0, 1, 10);
    gr.addEdge(0, 1, 10);
    gr.addEdge(0, 1, 10);

    gr.primsAlgo(0);
    
    cout << "-----------------------------" << endl;

    return 0;
}