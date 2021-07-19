class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0 ; i<s.size() ; i++) {
            //push characters in the stack till we encounter closing bracket
            if(s[i] != ']') {
                st.push(s[i]);
            }
            //work to be done if we encounter closing bracket
            else {
                //find the string that is to be repeated and store it in curr
                string curr = "";
                while(!st.empty() && st.top() != '[') {
                    curr = st.top() + curr;
                    st.pop();
                }
                st.pop();
                //this will help in identifying the number of times curr string will be repeated
                string number = "";
                while(!st.empty() && isdigit(st.top())) {
                    number = st.top() + number;
                    st.pop();
                }
                //convert the number string into integer
                int repetition = stoi(number);
                //repeat the curr string repetition times
                while(repetition--) {
                    for(int j=0 ; j<curr.size() ; j++) {
                        st.push(curr[j]);
                    }
                }
            }
        }
        
        //here we will have required answer in the stack,
        //our task is to pop the elements one by one from the stack,
        //and store it in resultant string
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};