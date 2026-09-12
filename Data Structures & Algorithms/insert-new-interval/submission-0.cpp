class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        int n = intervals.size();
        int start = newInterval[0]; int position = n;
        for(int i=0;i<n;i++){
            if(start <= intervals[i][0]) {
                position = i; break;    
            }
        }

        intervals.insert(intervals.begin()+position, newInterval);
        n= n+1;
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
