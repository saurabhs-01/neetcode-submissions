class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        for(int i=0;i<n;){
            int temp=i+1; int prevEnd = intervals[i][1];
            while(temp<n && intervals[temp][0] <= prevEnd) {
                prevEnd = max(intervals[temp][1], prevEnd); temp++;
            }
            vector<int> ans; ans.push_back(intervals[i][0]); ans.push_back(prevEnd);
            res.push_back(ans);
            i=temp;
        }

        return res;
    }
};
