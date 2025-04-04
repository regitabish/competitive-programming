class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> mp;
        int ans = 0;
        mp[0] = 1;
        for(auto num:nums){
            sum += num;
            ans += mp[sum-k];
            mp[sum]++;
        } 
        return ans;
    }
};