class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        if(n == 0) return tasks.size();
       int res = 0;
        unordered_map<int, int> counter;
        priority_queue<pair<int, int>> pq;
        vector<int> v(26, 0);

        int slot = 0;
        for (int i = 0; i < tasks.size(); i++) v[tasks[i]-65]++;

        for (int i=0;i<26;i++) {

            if(v[i] !=0) {
                pq.push({v[i], i});
            }
        }

        while (true) {

            if(pq.empty()) {
                int mini = findMin(counter, pq, v);
                if(mini == INT_MAX) break;
                res+= mini;
                continue;
            }

            int cnt = pq.top().first;
            int label = pq.top().second; pq.pop();

            if (counter[label] == 0) {

                for (auto& [key, count] : counter) {

                    if (count > 0) {
                        count--; if(count == 0 && v[key] > 0) pq.push({v[key], key});
                    }

                }
                v[label]--;
                if(v[label] > 0) counter[label] = n;
                res++;
            }

        }

        return res; 
    }

    int findMin(unordered_map<int, int>& counter, priority_queue<pair<int, int>>& pq,const vector<int>& v) {

        int mini = INT_MAX;
        for(auto it: counter) if(it.second !=0) mini = min(mini, it.second);

        if(mini != INT_MAX){
            for(auto& [key, count]: counter) {

                if(count > 0) {
                    count = count - mini;
                    if(count == 0 && v[key] > 0) pq.push({v[key], key});
                }
            }
        }

        return mini;
    }
};
