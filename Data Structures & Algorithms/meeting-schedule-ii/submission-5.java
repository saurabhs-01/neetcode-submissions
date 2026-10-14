/**
 * Definition of Interval:
 * public class Interval {
 *     public int start, end;
 *     public Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

class Solution {
  
    public int minMeetingRooms(List<Interval> intervals) {

        NavigableMap<Integer, Integer> mpp = new TreeMap<>(); 
        int maxi = 0;

        for(int i=0;i<intervals.size();i++) {

            System.out.println(intervals.get(i).start);
            mpp.put(intervals.get(i).start, mpp.getOrDefault(intervals.get(i).start,0)+1); 
            mpp.put(intervals.get(i).end, mpp.getOrDefault(intervals.get(i).end,0)-1); 
        }

        int count = 0;
        for(var it: mpp.entrySet()) {

            count+= it.getValue();
            maxi = Math.max(count, maxi);
        }

        return maxi;


    }
}
