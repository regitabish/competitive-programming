class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int i=1;i<=n;++i){
            for(int j=0;j<=i;++j){
                string subString = s.substr(j,i-j);
                if(dp[j]&&st.find(subString)!=st.end()){
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};