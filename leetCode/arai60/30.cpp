class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>st;
        for(auto mail:emails){
            string clean;
            for(auto c:mail){
                if(c=='+'||c=='@')break;
                if(c=='.')continue;
                clean += c;
            }
            clean+=mail.substr(mail.find('@'));
            st.insert(clean);
        }
        return st.size();
    }
};