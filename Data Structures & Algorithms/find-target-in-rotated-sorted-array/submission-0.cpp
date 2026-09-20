class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0; int h = n-1;
        while(l <= h) {

            int mid = l + (h-l)/2;
            if(nums[mid] == target) return mid;
            if(nums[n-1] > nums[0]) { //normal, sorted array
               if(nums[mid] > target) h= mid-1;
               else l = mid+1;
               continue;
            }
            else{ //rotated
               if(nums[mid] > nums[n-1]) { // first half
                   if(nums[mid] < target || target <= nums[n-1]) l=mid+1;
                   else h=mid-1;
                   continue;
               }
               else{ //second half
                  if(target > nums[n-1] || nums[mid] > target) h=mid-1;
                  else l=mid+1;
               }
            }
        }

        return -1;
    }
};
