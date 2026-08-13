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

        for(int i=0;i<n-1;i++) {

            if(intervals[i][1] > intervals[i+1][0]) return false;
        }

        return true;
    }

    


};
