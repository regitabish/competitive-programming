class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<nums1.size();++i){
            for(int j=0;j<nums2.size();++j){
                int v1 = nums1.at(i);
                int v2 = nums2.at(j);
                int sum = v1 + v2;
                if(pq.size()<k){
                    pq.push({sum,{v1,v2}});
                }else if(pq.top().first>sum){
                    pq.pop();
                    pq.push({sum,{v1,v2}});
                }else{
                    break;
                }

            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};