class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> res;
        map<double, vector<int>> mpp;

        int n = points.size();
        for (int i = 0; i < n; i++) {

            double dist = sqrt((points[i][0] * points[i][0]) +
                               (points[i][1] * points[i][1]));
            mpp[dist].push_back(i);
        }

        for (auto [dist, indices] : mpp) {

            for (auto it : indices) {
                if (res.size() >= k)
                    return res;
                res.push_back(points[it]);
            }
        }

        return res;
    }
};
