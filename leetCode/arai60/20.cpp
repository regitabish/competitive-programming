class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        for(auto n:nums1){
            mp[n]++;
        }
        vector<int>ans;
        map<int,int>mp2;
        for(auto n:nums2){
            
            if(mp.count(n)&&!mp2.count(n)){
                ans.push_back(n);
                mp2[n]++;
            }
        }
        return ans;
    }
};