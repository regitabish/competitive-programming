class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int> mp;
        for(auto n:nums){
            mp[n]++;
        }
        for(auto m:mp){
            pq.push({m.second,m.first});
        }
        vector<int> ans;
        for(int i=0;i<k;++i){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};