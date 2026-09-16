class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int res = 0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it: times) {
            adj[it[0]-1].push_back({it[1]-1, it[2]});
        }

        vector<int> dist(n, INT_MAX);
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>> pq;
        pq.push({0,k-1});

        while(!pq.empty()) {
            int val = pq.top().second; int w = pq.top().first; pq.pop();
            if(dist[val] < w) continue;
            dist[val] = w;

            for(auto& it: adj[val]) {
                if(dist[it.first] > w + it.second) {
                    pq.push({w+it.second, it.first});
                }
            }
        }

        for(auto& it: dist) {
            if(it == INT_MAX) return -1;
            res = max(res, it);
        }

        return res;
    }
};
