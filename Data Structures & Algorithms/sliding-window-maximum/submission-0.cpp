class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> res;
        int n = nums.size();
        using pii = pair<int, int>;
        priority_queue<pii> pq;

        for(int i=0;i<k;i++){
            pq.push({nums[i], i});
        }
        res.push_back(pq.top().first);
        int start = 0; int end = k-1;
        while(end+1 < n && !pq.empty()) {

            start++; end++;
            pq.push({nums[end], end});
            while(!pq.empty() && (pq.top().second > end ||  pq.top().second < start)) pq.pop();

            if(!pq.empty()) res.push_back(pq.top().first);
        }

        return res;
    }
};
