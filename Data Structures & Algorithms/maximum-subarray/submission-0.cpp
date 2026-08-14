class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int res = INT_MIN;
        int n = nums.size();
        int total= 0;

        for(int i=0;i<n;i++) {

            total+= nums[i];
            res = max(res, total);
            if(total < 0) {
                total=0;
                continue;
            }
            
        }

        return res;
    }
};
