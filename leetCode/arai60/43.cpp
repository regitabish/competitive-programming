class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(auto n:nums1){
            mp[n]++;
        }
        vector<int> ans;
        unordered_set<int> st;
        for(auto n:nums2){
            if(mp.count(n) && !st.count(n)){
                ans.push_back(n);
                st.insert(n);
            }
        }
        return ans;
    }
};