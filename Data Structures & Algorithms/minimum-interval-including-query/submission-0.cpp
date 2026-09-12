class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        int n = queries.size();
        vector<int> res(n, -1);

        sort(intervals.begin(), intervals.end());
        multimap<int, int> mpp;

        for(int i=0;i<n;i++){
            mpp.insert({queries[i], i});
        }

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq; //Min Heap

        int lastI = 0;
        for(auto it: mpp){

            int val = it.first; int index = it.second;
            for(int i=lastI;i<intervals.size();i++) {
                lastI = i;
                if(val < intervals[i][0]) break;
                pq.push({intervals[i][1] - intervals[i][0]+1, intervals[i][1]});
            }

            while(!pq.empty()){
                int s = pq.top().first; int end = pq.top().second;
                if(val > end) pq.pop();
                else{
                    res[index] = s; break;
                }
            }
        }

        return res;
    }
};
