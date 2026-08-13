/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& interval) {
        
        int n = interval.size();
        vector<vector<int>> intervals(n);
        for(int i=0;i<n;i++) {
            intervals[i].push_back(interval[i].start);
            intervals[i].push_back(interval[i].end);
        }
        sort(intervals.begin(), intervals.end());

        for(int i=0;i<n;i++) {

            cout << i << " ";
            if(i == 0) {
                if(findIndex(1,n-1, intervals, intervals[i][0], 0) || findIndex(1,n-1, intervals, intervals[i][1], 1)) return false;
            }
            else if(i == n-1) {
                if(findIndex(0,n-2, intervals, intervals[i][0], 0) || findIndex(0,n-2, intervals, intervals[i][1], 1)) return false;
            }
            else{
              if(findIndex(0,i-1, intervals, intervals[i][0], 0) || findIndex(0,i-1, intervals, intervals[i][1], 1)) return false; 
              if(findIndex(i+1,n-1, intervals, intervals[i][0], 0) || findIndex(i+1,n-1, intervals, intervals[i][1], 1)) return false; 
            }
        }

        return true;

    }

    bool findIndex(int l, int h, const vector<vector<int>>& intervals, int x, int type) {

        int mid = l + (h-l)/2;
        while(l <= h) {
            
            mid = l + (h-l)/2;
            if(type == 0 && x== intervals[mid][0]) return true;
            if(type == 1 && x == intervals[mid][1]) return true;

            if(x > intervals[mid][0] && x < intervals[mid][1]) return true;
            else if(x>=intervals[mid][1]) l=mid+1;
            else h=mid-1;
        }

        return false;
    }


};
