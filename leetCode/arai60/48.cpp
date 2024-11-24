class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> correctMail;
        for(auto mail:emails){
            string adress;
            for(auto c:mail){
                if(c=='.')continue;
                if(c=='+'||c=='@')break;
                adress+=c;
            }
            adress += mail.substr(mail.find('@'));
            correctMail.insert(adress);
        }
        return correctMail.size();
    }
};