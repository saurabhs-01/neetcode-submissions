class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        int res = INT_MAX;
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        using pii = pair<int, pair<int, int>>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, {src, 0}});
        vector<int> prices(n, INT_MAX);
        vector<int> stops(n, INT_MAX);
        while(!pq.empty()){
            int price = pq.top().first; int val = pq.top().second.first; int steps = pq.top().second.second;
            pq.pop();
            if(prices[val] > price) {
                prices[val] = price;
            }
            if(stops[val] > steps) {
                stops[val] = steps;
            }
            if(steps > k) continue;

            for(auto it: adj[val]) {
                if(prices[it.first] > price + it.second || stops[it.first] > steps+1) {
                    pq.push({price + it.second, {it.first, steps+1}});
                }
            }
        }

        return prices[dst] == INT_MAX ? -1: prices[dst];
    }
};
