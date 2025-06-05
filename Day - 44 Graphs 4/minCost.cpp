// Min Cost to Connect Points
// LeetCode 1584

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int src = 0;
        vector<bool> mst(V, false);
        pq.push(make_pair(0, src));
        int minCost = 0;

         while(pq.size() > 0) {
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if(!mst[u]) {
                mst[u] = true;
                minCost += cost;

                for(int v=0; v<V; v++) {
                    if(u != v) {
                        int wt = abs(points[u][0] - points[v][0])
                                + abs(points[u][1] - points[v][1]);
                        pq.push(make_pair(wt, v));
                    }
                }
            }
        }
        return minCost;
    }
};