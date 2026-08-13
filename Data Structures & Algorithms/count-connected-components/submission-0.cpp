class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        int res = 0;
        vector<vector<int>> adj(n);
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                res++;
            }
        }

        return res;
    }

    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& vis) {

        vis[node] = true;
        for(auto it: adj[node]) {
            if(!vis[it]) dfs(it, adj, vis);
        }
    }
};
