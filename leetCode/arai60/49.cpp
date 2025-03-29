class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
            mp[nums.at(i)] = i;
        }
        for(int i=0;i<nums.size();++i){
            int n= nums.at(i);
            int diff = target - n;
            if(mp.count(diff) && mp[diff]!=i){
                
                ans.push_back(i);
                ans.push_back(mp[diff]);
                return ans;
            }
        }
        return ans;
    }
};