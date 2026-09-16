class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = 0;
        for(const auto& it: prerequisites) {
            n = max({n, it[0], it[1]});
        }

        vector<vector<int>> adj(n+1); vector<int> inDegree(n+1,0);
        for(const auto& it: prerequisites) {
            adj[it[0]].push_back(it[1]);
            inDegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<=n;i++){
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int val = q.front(); q.pop();
            count++;
            for(auto it: adj[val]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        return count == n+1;
    }
};
