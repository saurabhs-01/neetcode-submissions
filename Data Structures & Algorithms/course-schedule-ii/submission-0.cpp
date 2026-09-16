class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> res;

        vector<vector<int>> adj(numCourses); vector<int> inDegree(numCourses,0);
        for(auto& it: prerequisites) {
            adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int val = q.front(); q.pop();
            res.push_back(val);
            count++;
            for(auto it: adj[val]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        if(count != numCourses) return {};

        return res;
    }
};
