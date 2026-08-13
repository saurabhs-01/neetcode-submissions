class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_map<char, bool>> row(9);
        vector<unordered_map<char, bool>> col(9);

        int r=0;
        while(r < 9)
        {
            int c = 0;
            while (c < 9) { // grid
                unordered_map<char, bool> grid;
                for (int i = r; i < r+3; i++) {

                    for (int j = c; j < c + 3; j++) {
                        
                        if(board[i][j] == '.') continue;
                        if ((grid.find(board[i][j]) != grid.end() ||
                             row[i].find(board[i][j]) != row[i].end() ||
                            col[j].find(board[i][j]) != col[j].end())) return false;
                        grid[board[i][j]] = true;
                        row[i][board[i][j]] = true;
                        col[j][board[i][j]] = true;
                    }
                }
                c+=3;
            }
            r+=3;
        }

        return true;
    }
};
