class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<nums1.size();++i){
            for(int j=0;j<nums2.size();++j){
                int sum = nums1.at(i) + nums2.at(j);
                if(pq.size()<k){
                    pq.push({sum,{nums1.at(i),nums2.at(j)}});
                }
                else if(sum<pq.top().first){
                    pq.pop();
                    pq.push({sum,{nums1.at(i),nums2.at(j)}});
                }
                else{
                    break;
                }
            }
        }

        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;

    }
};