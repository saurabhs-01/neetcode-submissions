class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int m = grid.size(); int n = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) pq.push({0, {i,j}});
            }
        }

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        while(!pq.empty()){
            
            
            int dist = pq.top().first; int x = pq.top().second.first; int y = pq.top().second.second;
            pq.pop();
           

        if(x-1 >=0 && grid[x-1][y] == INT_MAX) {
            grid[x-1][y] = dist+1;
            pq.push({dist+1, {x-1, y}});
        }
        if(x+1 < m && grid[x+1][y]== INT_MAX) {
            grid[x+1][y] = dist+1;
            pq.push({dist+1, {x+1, y}});
        } 
        if(y-1 >=0 && grid[x][y-1] ==INT_MAX) {
            grid[x][y-1]= dist+1;
            pq.push({dist+1, {x, y-1}});
        } 
        if(y+1 < n && grid[x][y+1]== INT_MAX) {
            grid[x][y+1] = dist+1;
            pq.push({dist+1, {x, y+1}});
        } 
        }
    }

};
