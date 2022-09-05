class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int c=0 ; c<s.size() ; c++) {
            if(s[c] == '(' || s[c] == '[' || s[c] == '{') {
                st.push(s[c]);
            }
            else {
                if(st.empty() || (st.top() == '(' && s[c] != ')') || (st.top() == '{' && s[c] != '}') || (st.top() == '[' && s[c] != ']')) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};