class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int res = 0; queue<pair<int, pair<int, int>>> q;
        int m = grid.size(); int n = grid[0].size(); int total0 = 0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }
                else if(grid[i][j] == 1) total0++;
            }
        }

        while(!q.empty()) {

            int t = q.front().first; int x = q.front().second.first; int y = q.front().second.second; q.pop();
            res = max(res, t);

            if(x-1 >= 0 && grid[x-1][y] == 1) {
                total0--;
                grid[x-1][y] = 2; q.push({t+1, {x-1, y}});
            }
            if(x+1 < m && grid[x+1][y] == 1) {
                total0--;
                grid[x+1][y] = 2; q.push({t+1, {x+1, y}});
            }
            if(y-1 >= 0 && grid[x][y-1] == 1) {
                total0--;
                grid[x][y-1] = 2; q.push({t+1, {x, y-1}});
            }
            if(y+1 < n && grid[x][y+1] == 1) {
                total0--;
                grid[x][y+1] = 2; q.push({t+1, {x, y+1}});
            }
        }

        if(total0 != 0) return -1;
        return res;
    }
};
