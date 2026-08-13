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
    int minMeetingRooms(vector<Interval>& intervals) {
        
        map<int, int> mpp; int overlaps = 0; int maxOverlaps = 0;
        for(auto it: intervals) {

            mpp[it.start]++;
            mpp[it.end]--;

        }

        for(auto it: mpp) {
            
            overlaps+= it.second;
            maxOverlaps = max(maxOverlaps, overlaps);
        }

        return maxOverlaps;

    }
};
