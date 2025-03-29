class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(auto mail:emails){
            string cleanMail;
            for(char c:mail){
                if(c=='@'||c=='+')break;
                if(c=='.')continue;
                cleanMail += c;
            }
            cleanMail += mail.substr(mail.find('@'));
            st.insert(cleanMail);
        }
        return st.size();
    }
};