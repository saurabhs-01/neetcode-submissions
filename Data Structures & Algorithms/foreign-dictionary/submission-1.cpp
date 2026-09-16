class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        
        if(words.size() == 1) return words[0];
        string res;
        vector<vector<int>> adj(26); vector<int> inDegree(26,0);
        set<int> st;

        int n = words.size();
        for(int i=0;i<n-1;i++) {
            string x = words[i];
            string y = words[i+1];
            int n1 = x.length(); int n2 = y.length();
            int m=0; int n=0;
            while(m < n1 && n < n2) {
                if(x[m] == y[n]) {
                    st.insert(x[m]-97); st.insert(y[n]-97);
                    m++; n++; 
                    if(n == n2 && m < n1) return "";
                    continue;
                }
                adj[x[m]-97].push_back(y[n]-97);
                inDegree[y[n]-97]++;
                st.insert(x[m]-97); st.insert(y[n]-97);
                m++; n++;
                while(m < n1) {
                    st.insert(x[m]-97); m++;
                }
                while(n < n2) {
                    st.insert(y[n]-97); n++;
                }
            }
        }

        queue<int> q;
        for(int i=0;i<26;i++){
            if(st.find(i) != st.end() && inDegree[i] == 0) q.push(i);
        }

        int count = 0;
        while(!q.empty()) {
            int val= q.front(); q.pop(); count++;
            res+= ((char)(val+97));
            for(auto it: adj[val]) {
                if(--inDegree[it] == 0) q.push(it);
            }
        }

        if(count != st.size()) return "";
        return res;

    }
};
