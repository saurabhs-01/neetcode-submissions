class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 0;
        unordered_map<string, vector<string>> adj;

        int m = beginWord.size();
        unordered_set<string> words;

        for (auto word : wordList) {
            if (word.size() != m) continue;
            string original = word;
            for (int i = 0; i < m; i++) {
                char oldChar = word[i];
                word[i] = '*';

                adj[word].push_back(original);

                word[i] = oldChar;
            }
        }

        queue<pair<int, string>> q;
        q.push({1, beginWord});

        while (!q.empty()) {
            int t = q.front().first;
            string word = q.front().second;
            q.pop();

            if(word == endWord) return t;

            for (int i = 0; i < m; i++) {
                char oldChar = word[i];
                word[i] = '*';
                
                for(auto it: adj[word]){

                    if(words.find(it) != words.end()) continue;
                    q.push({t+1, it}); words.insert(it);
                }
                word[i] = oldChar;
            }
        }

        return 0;
    }
};
