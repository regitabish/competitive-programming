class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end())return 0;
        queue<string>q;
        q.push(beginWord);
        unordered_set<string>vis;
        int ans = 0;
        while(!q.empty()){
            int qSize = q.size();
            while(qSize--){
                string word = q.front();
                q.pop();
                for(int i=0;i<word.size();i++){
                    char original = word[i];
                    if(word==endWord)return ans+1;
                    for(char c='a';c<='z';c++){
                        word[i] = c;
                        if(st.find(word)!=st.end()&&vis.find(word)==vis.end()){
                            vis.insert(word);
                            q.push(word);
                        }
                    }
                    word[i] = original;
                    
                }
            }
            ans++;
        }
        return 0;
    }
};