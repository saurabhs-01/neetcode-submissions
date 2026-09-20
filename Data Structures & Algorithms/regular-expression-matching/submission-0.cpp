class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n1 = s.length(); int n2= p.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));
        return solve(0, 0, s, p, dp);
    }

    bool solve(int i, int j,const string& s,const string& p,vector<vector<int>>& dp) {

        int n1 = s.length(); int n2 = p.length();
        if(i== n1 && j== n2) return true;

        if(j== n2) return false;

        if(i==n1) {
            if(j < n2-1 && p[j+1] == '*') {
                if(solve(i, j+2, s, p, dp)) {
                    dp[i][j] = 1; return true;
                }
                {
                    dp[i][j] = 0; return false;
                }
            }
            dp[i][j] =0; return false;
        }

        if(dp[i][j] != -1) return dp[i][j] == 1;

        if(j < n2-1 && p[j+1] == '*') {
            // skip
            if(solve(i, j+2, s, p, dp)) {
                dp[i][j]= 1; return true;
            }
            //take
            if(p[j] == '.' || p[j] == s[i]) {
                if(solve(i+1, j, s, p, dp)) {
                    dp[i][j] = 1; return true;
                } 
            }
        }
        if((p[j] == '.' || s[i] == p[j]) &&  solve(i+1,j+1, s, p, dp)) {
            dp[i][j] = 1; return true;
        }

        dp[i][j] = 0; return false;
    }
};
