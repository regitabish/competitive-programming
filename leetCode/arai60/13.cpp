class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto n:nums){
            mp[n]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto n:mp){
            pq.push({n.second,n.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};