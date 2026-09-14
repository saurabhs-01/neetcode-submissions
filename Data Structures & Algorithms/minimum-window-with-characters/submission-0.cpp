class Solution {
public:
    string minWindow(string s, string t) {
        
        string res = "";
        int n = s.size();
        unordered_map<char, int> mpp;

        for (auto c : t)
            mpp[c]++;

        int start = 0;
        int end = 0;
        int mini = INT_MAX;
        int first = -1;
        int last = -1;
        while (start <= end && end < n) {

            char c = s[end];
            if (mpp.find(c) != mpp.end()) {
                mpp[c]--;

                while (start <= end && !isMissing(mpp)) {

                    if (mini > (end - start + 1)) {
                        mini = end - start + 1;
                        first = start;
                        last = end;
                    }
                    mpp[s[start]]++;
                    start++;
                    while (start <= end && mpp.find(s[start]) == mpp.end())
                        start++;
                }
            }

            while (start <= end && mpp.find(s[start]) == mpp.end())
                start++;

            end++;
        }

        if (first == -1)
            return "";
        return s.substr(first, last - first + 1);
    }

    bool isMissing(const unordered_map<char, int>& mpp) {
        bool missing = false;
        for (auto it : mpp) {
            if (it.second > 0) {
                missing = true;
                break;
            }
        }

        return missing;
    }
};
