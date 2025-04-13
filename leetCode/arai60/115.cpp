class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using T = tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<>> pq;
        int n = nums1.size();
        for(int i=0;i<n;++i){
            pq.emplace(nums1[i]+nums2[0],i,0);
        }
        vector<vector<int>> ans;
        while(!pq.empty()&&k--){
            auto [sum,n1,n2] = pq.top();
            ans.push_back({nums1[n1],nums2[n2]});
            pq.pop();
            if(n2+1<nums2.size()){
                pq.emplace(nums1[n1]+nums2[n2+1],n1,n2+1);
            }
        }
        return ans;
    }
};