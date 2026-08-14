class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n,0);
        int product = 1; int fIndex = -1; int sIndex = -1;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) {
                if(fIndex == -1) fIndex = i;
                else if(sIndex == -1) sIndex = i;
                else {
                    product = 0;
                    break;
                }
                continue;
            }
            product = product * nums[i];
        }

        if(fIndex != -1 && sIndex != -1) return res;

        if(fIndex != -1) {
            res[fIndex] = product;
            return res;
        }

        for(int i = 0;i<n;i++) {
            res[i] = product/nums[i];
        }

        return res;
    }
};
