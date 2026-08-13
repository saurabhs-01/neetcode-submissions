class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int res = 0;
        int i=0; int n = heights.size(); int j = n-1; 

        while(i <= j && j< n) {

            res = max(res, (min(heights[i], heights[j]))*(j-i));
            if(heights[j] >= heights[i]) i++;
            else j--;
        }

        return res;
    }
};
