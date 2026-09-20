class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, nums, dp);
    }

    int solve(int start, int end,const vector<int>& nums, vector<vector<int>>& dp) {

        if(start > end) return 0;

        int lValue = 1; int rValue = 1; int n = nums.size();
        if(start != 0) lValue = nums[start-1];
        if(end != n-1) rValue = nums[end+1];

        if(start==end) return dp[start][end] = nums[start]*lValue * rValue;

        if(dp[start][end] != -1) return dp[start][end];

        int maxi = 0;
        for(int i=start;i<= end;i++) { // i denotes the last balloon to be bursted
           maxi = max(maxi, lValue*nums[i]*rValue + solve(start, i-1, nums, dp) + solve(i+1, end, nums, dp));
        }

        return dp[start][end] = maxi;
    }
};
