class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        unordered_map<char, int> mpp;
        mpp['('] = 1; mpp[')'] = -1; 
        mpp['{'] = 2; mpp['}'] = -2;
        mpp['['] = 3; mpp[']'] = -3;

        for(auto c: s) {

            if(mpp[c] > 0) stk.push(c);
            else{
                if(stk.empty() || (mpp[stk.top()]+mpp[c] != 0)) return false;
                stk.pop();
            }
        }

        return stk.empty();
    }
};
