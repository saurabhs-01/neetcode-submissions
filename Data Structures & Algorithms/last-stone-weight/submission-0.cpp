class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;

        for(auto it: stones) pq.push(it);

        while(!pq.empty()) {

            if(pq.size() >= 2) {
                int y = pq.top(); pq.pop(); int x = pq.top(); pq.pop();
                if(y!=x) pq.push(y-x);
            }
            else return pq.top();
        }

        return 0;
    }
};
