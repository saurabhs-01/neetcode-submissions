class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<bool> lDiagonals((n - 1) * 2 + 1, false);
        vector<bool> rDiagonals((n - 1) * 2 + 1, false);
        vector<bool> rows(n, false);
        vector<bool> cols(n, false);
        vector<pair<int, int>> ans;

        solve(n, rows, cols, lDiagonals, rDiagonals, ans, res);

        return res;
    }

    void solve(int total, vector<bool>& rows, vector<bool>& cols,
               vector<bool>& lDiagonals, vector<bool>& rDiagonals,
               vector<pair<int, int>>& ans, vector<vector<string>>& res) {

        int n = rows.size();
        if (total == 0) {

            string s(n, '.');
            vector<string> stringV(n, s);
            for (auto [x, y] : ans) {
                stringV[x][y] = 'Q';
            }
            res.push_back(stringV);
            return;
        }

        for (int i = 0; i < n && !rows[i]; i++) {
            for (int j = 0; j < n; j++) {
                if (cols[j])
                    continue;
                int lD = (i >=j) ? (i-j) : (n-1 + j-i);
                int nj = n-1-j;
                int rD = (i >=nj) ? (i - nj) : (n-1 + nj -i);
                if (lDiagonals[lD] || rDiagonals[rD])
                    continue;
                rows[i] = true;
                cols[j] = true;
                lDiagonals[lD] = true;
                rDiagonals[rD] = true;
                ans.push_back({i, j});
                solve(total - 1, rows, cols, lDiagonals, rDiagonals, ans, res);
                ans.pop_back();
                rows[i] = false;
                cols[j] = false;
                lDiagonals[lD] = false;
                rDiagonals[rD] = false;
            }
        }
    }
};
