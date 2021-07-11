class Solution {
public:
    bool HasHigherPrecedence(char c1, char c2) {
        if (c1 == '+' || c1 == '-')
            return c2 == '+' || c2 == '-';
        return true;
    }
    int calculate(string s) {
        s += " ";
        vector<string> postfix;
        stack<char> st;
        string curr_num = "";
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] !=' '){
                curr_num += string(1,s[i]);
                continue;
            }
            //if curr_num is not empty
            if(curr_num != ""){
                postfix.push_back(curr_num);
                curr_num = "";
            }
            //if space is encountered
            if(s[i] == ' '){
                continue;
            }
            //we have encountered a operator
            while(!st.empty() && HasHigherPrecedence(st.top(),s[i])){
                postfix.push_back(string(1,st.top()));
                st.pop();
            }
            st.push(s[i]);
            
            
        }
        //push the remaining operators
        while(!st.empty()){
            postfix.push_back(string(1,st.top()));
            st.pop();
        }
        //start evaluating postfix now
        stack<int> st2;
        for (int i = 0; i < postfix.size(); i++) {
            if (postfix[i] != "+" && postfix[i] != "-" && postfix[i] != "*" && postfix[i] != "/") {
                st2.push(stoi(postfix[i]));
                continue;
            }
            int op2 = st2.top();
            st2.pop();
            int op1 = st2.top();
            st2.pop();

            if (postfix[i] == "+")
                st2.push(op1 + op2);
            else if (postfix[i] == "-")
                st2.push(op1 - op2);
            else if (postfix[i] == "*")
                st2.push(op1 * op2);
            else
                st2.push(op1 / op2);

        }

        return st2.top();
    }
};