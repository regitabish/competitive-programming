class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end())
            return 0;

        queue<string> q;
        q.push(beginWord);
        unordered_set<string> vis;
        vis.insert(beginWord);
        int ans = 1;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string s = q.front();
                if (s == endWord)
                    return ans;
                q.pop();
                for (int i = 0; i < s.size(); ++i) {
                    char original = s[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == original)
                            continue;
                        s[i] = c;

                        if (st.find(s) != st.end() &&
                            vis.find(s) == vis.end()) {
                            vis.insert(s);
                            q.push(s);
                        }
                    }
                    s[i] = original;
                }
            }
            ans++;
        }
        return 0;
    }
};