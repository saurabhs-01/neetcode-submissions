class Solution {
public:
    int trap(vector<int>& height) {
        
        int res = 0;
        int n = height.size();
        vector<int> left_max(n);
        vector<int> right_max(n);

        int maxi = height[0];
        for(int i=1;i<n;i++) {

            maxi = max(maxi, height[i]);
            left_max[i]= maxi;
        }

        maxi = height[n-1];
        for(int i=n-1;i>=0;i--) {

            maxi = max(maxi, height[i]);
            right_max[i] = max(maxi, height[i]);
        }

        for(int i=1;i<n-1;i++){

            int diff = min(left_max[i], right_max[i]) - height[i];
            if(diff > 0) res+= diff;
        }

        return res;
    }
};
