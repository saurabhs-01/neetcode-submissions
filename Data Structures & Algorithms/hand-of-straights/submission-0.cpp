class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if ((hand.size() % groupSize) != 0)
            return false;
        map<int, int> mpp;

        for (auto it : hand)
            mpp[it]++;

        auto it = mpp.begin();
        while(it!=mpp.end()) {
            
            while(it != mpp.end() && it->second == 0) it++;
            if(it == mpp.end()) break;
            int start = it->first; it->second = it->second-1;
            for(int j=start+1;j<start+groupSize;j++) {
                if(mpp.find(j) == mpp.end() || mpp[j] == 0) return false;
                mpp[j]--;
            }
        }

        return true;
    }
};
