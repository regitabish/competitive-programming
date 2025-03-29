class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int>mp;
        for(auto n:nums){
            mp[n]++;
        }
        for(i:mp){
            pq.push(i.second,i.first);
        }
        vector<int> ans;
        for(int i=0;i<k;++i){
            ans.push_back(pq.top().second)
            pq.pop();
        }
        return ans;
    }
};