class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> opp;
        opp[')'] = '(';
        opp['}'] = '{';
        opp[']'] = '[';
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else{
                if(st.empty() || st.top() != opp[ch])    return false;
                st.pop();
            }
        }
        return  st.empty() ? true : false;
    }
};