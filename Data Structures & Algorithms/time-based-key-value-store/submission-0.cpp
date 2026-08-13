class TimeMap {
   private:
    unordered_map<string, vector<pair<int, string>>> mpp;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { mpp[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        int n = mpp[key].size();
        if (n == 0 || mpp[key][0].first > timestamp) return "";

        int l = 0;
        int h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (mpp[key][mid].first == timestamp) {
                return mpp[key][mid].second;
            } else if (mpp[key][mid].first > timestamp) {
                h = mid - 1;
            } else
                l = mid + 1;
        }

        l = min(l, n - 1);
        if (mpp[key][l].first > timestamp) l = max(0, l - 1);
        return mpp[key][l].second;
    }
};
