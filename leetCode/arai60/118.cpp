class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n,0,0,"",res);
        return res;
    }
    void dfs(int n,int open,int close,string currStr,vector<string>& res){
        if(open<n){
            dfs(n,open+1,close,currStr+'(',res);
        }
        if(close<open){
            dfs(n,open,close+1,currStr+')',res);
        }
        if(open==n&&close==n){
            res.push_back(currStr);
        }
    }
};