class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int res = 1;
        vector<pair<int, double>> temp;
        int n = position.size();
        for(int i=0;i<n;i++) {
            temp.push_back({position[i], (1.0 *(target-position[i])/speed[i])});
        }

        sort(temp.begin(), temp.end());
        double prev = temp[n-1].second;
        for(int i=n-2;i>=0;i--) {
            double time = temp[i].second;
            if(time > prev) {
                res++;
                prev = time;
            }
        }

        return res;
    }
};
