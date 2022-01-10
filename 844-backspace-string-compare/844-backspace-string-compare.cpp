class Solution {
public:
    string solve(string &str) {
        int n = str.size();
        int cnt = 0;
        string res = "";
        for(int i=n-1 ; i>=0 ; i--) {
            char ch = str[i];
            if(ch == '#') {
                cnt++;
            }
            else {
                if(cnt > 0) {
                    cnt--;
                }
                else {
                    res += ch;
                }
            }
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {
        return solve(s)==solve(t);
//         stack<char> s1;
//         stack<char> s2;
//         for(int i=0 ; i<s.size() ; i++) {
//             if(!s1.empty() && s[i] == '#'){
//                 s1.pop();
//             }
//             else if(s[i] != '#'){
//                 s1.push(s[i]);
//             }
//         }
        
//         for(int i=0 ; i<t.size() ; i++) {
//             if(!s2.empty() && t[i] == '#'){
//                 s2.pop();
//             }
//             else if(s[i] != '#'){
//                 s2.push(t[i]);
//             }
//         }
//         while(!s1.empty() && !s2.empty())
//         {   
//             if(s1.top() != s2.top()){
//                 return false;
//             }
//             s1.pop();
//             s2.pop();                
//         }

//         if(!s1.empty()){
//             return false;
//         }
//         if(!s2.empty()){
//             return false;
//         }
            
//         return true;
    }
};