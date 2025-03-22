class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
            if(c=='(' || c=='{' || c=='[')st.push(c);
            else if(st.size() && st.top() == '(' && c == ')')st.pop();
            else if(st.size() && st.top() == '{' && c == '}')st.pop();
            else if(st.size() && st.top() == '[' && c == ']')st.pop();
            else st.push(c);
        }
        return !st.size();
    }
};