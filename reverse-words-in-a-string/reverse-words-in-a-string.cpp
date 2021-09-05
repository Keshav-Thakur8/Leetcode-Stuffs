class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        string help;
        for(int i=n-1 ; i>=0 ; i--) {
            if(s[i] != ' ') {
                help = s[i]+help;
            }
            else if(s[i] == ' '){
                if(!help.empty()) {
                    ans += help + ' ';
                    help.clear();
                }
                
            }
        }
        if(!help.empty()) {
            ans += help;
        }
        //for removing leading or trailing spaces
        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};