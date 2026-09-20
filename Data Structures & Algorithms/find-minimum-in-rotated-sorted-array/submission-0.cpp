class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int mini = 1000;
        int n = nums.size();
        if(nums[0] <= nums[n-1]) return nums[0];

        int l = 0; int h = n-1;

        while(l<=h) {
            int mid = l + (h-l)/2;
            mini = min(mini, nums[mid]);
            if(nums[mid] >= nums[0]) l = mid+1;
            else h = mid-1;
        }

        return mini;
    }
};
