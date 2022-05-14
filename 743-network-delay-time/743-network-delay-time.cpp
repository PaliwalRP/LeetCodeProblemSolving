class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> g(N + 1);
        unordered_map<int, int> visited;
        // GRAPH CONSTRUCTION
        for (auto& time : times)
        {
            int u = time[0], v = time[1], w = time[2];
            g[u].emplace_back(v, w);
        }
        // DIJKSTRA 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, K);
        while (pq.size())
        {
            auto p = pq.top();
            int u = p.second, dist = p.first;
            pq.pop();
            if (visited.find(u) != visited.end())continue;
            visited[u] = dist;
            for (auto& e : g[u])
                pq.emplace(dist + e.second, e.first);
        }
       // TO FIND LARGEST DELAY
        if (visited.size() != N)return -1;
        int res = 0;
        for (auto& p : visited)res = max(res, p.second);
        return res;
    }
};