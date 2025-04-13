class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>>res;
        dfs(candidates,target,0,res,curr);
        return res;
    }
    void dfs(vector<int>& candidates,int target,int index,vector<vector<int>>&res, vector<int>& curr){
        if(target==0){
            res.push_back(curr);
            return ;
        }
        if(target<0){
            return ;
        }
        for(int i=index;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i,res,curr);
            curr.pop_back();
        }
    }
};