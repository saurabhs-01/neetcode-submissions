class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

      int res = 0; int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        for(int i=0;i<n;){
            
            int temp = i+1;
            while(temp < n && (intervals[temp][0] < intervals[i][1])) {
                res++;
                if(intervals[temp][1] < intervals[i][1]) {
                    i=temp;
                }
                temp++;
            }

            i=temp;
    
        }

        return res;
        
    }
};
