class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }
        for(int i=0;i<s.size();++i){
            char c = s.at(i);
            if(mp[c]==1){
                return i;
            }
        }
        return -1;
    }
};