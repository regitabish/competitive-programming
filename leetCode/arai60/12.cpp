class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto n : nums) {
            mp[n]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto i : mp) {
            pq.push({i.second, i.first});
            /* if (pq.size() > k) {
                pq.pop();
            } */
        }
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};