class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),sordList.end());
        if(st.find(endWord)==st.end())return 0;
        unordered_set<string> vis;
        queue<string>q;
        q.push(beginWord);
        vis.insert(beginWord);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string str = q.front();
                q.pop();
                if(str==endWord)return ans;
                for(int i=0;i<str.size();++i){
                    char original = str[i];
                    for(char c='a';c<='z';c++){
                        if(str[i]==c)continue;
                        str[i] = c;
                        
                        if(st.find(str)!=st.end()&&vis.find(str)==vis.end()){
                            q.push(str);
                            vis.insert(str);
                        }
                    }
                    str[i] = original;
                }

            }
            ans++;
        }
        return 0;

    }
};