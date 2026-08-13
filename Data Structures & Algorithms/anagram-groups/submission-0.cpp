class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> res;
        unordered_map<string, int> mpp;

        int n = strs.size(); int x = 0;
        for(int i=0;i<n;i++){
            
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            if(mpp.find(temp) == mpp.end()){
                res.push_back({}); 
                mpp[temp] = x; x++;
            }
            res[mpp[temp]].push_back(strs[i]);
           
        }

        return res;
    }
};
