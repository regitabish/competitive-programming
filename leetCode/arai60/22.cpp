class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>>mp;
        for(auto x:strs){
            string word = x;
            sort(x.begin(),x.end());
            mp[x].push_back(word);
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};