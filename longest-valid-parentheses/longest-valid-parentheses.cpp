class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int t = st.top();
            if(t!=-1 && s[i]==')' && s[t]=='(')
            {
                st.pop();
                ans = max(ans,i-st.top());
            }
            else
                st.push(i);
        }
        return ans;
    }
};