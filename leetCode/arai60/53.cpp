class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> ans;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                int sum = nums1.at(i) + nums2.at(j);
                int n1 = nums1.at(i);
                int n2 = nums2.at(j);
                if (pq.size() < k) {
                    pq.push({sum, {n1, n2}});
                } else if (pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {n1, n2}});
                } else {
                    break;
                }
            }
        }
        while (!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};