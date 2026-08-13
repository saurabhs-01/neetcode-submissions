class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

      vector<int> res;
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mpp;
        for(auto it: nums) mpp[it]++;

        for(auto [key, value] : mpp){
            pq.push({value, key});
        }

        while(!pq.empty() && k>0){
            res.push_back(pq.top().second);
            pq.pop(); k--;
        }

        return res;  
    }
};
