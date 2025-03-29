class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
            int diff = target - nums.at(i);
            if(mp.count(diff)){
                ans.push_back(mp[diff]);
                ans.push_back(i);
                return ans;
            }
            mp[nums.at(i)] = i;
        
        }
        return ans;
    }
};