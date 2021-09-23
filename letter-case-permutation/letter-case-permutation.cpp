class Solution {
public:
    vector<string> ans;
    void solve(string s, string temp, int i) {
        if(i == s.size()) {
            ans.push_back(temp);
            return;
        }
        
        if(isdigit(s[i])) {
            temp.push_back(s[i]);
            solve(s, temp, i+1);
        }
        else {
            string s1 = temp;
            s1.push_back(tolower(s[i]));
            solve(s, s1, i+1);
            
            string s2 = temp;
            s2.push_back(toupper(s[i]));
            solve(s, s2, i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        string temp = "";
        solve(s, temp, 0);
        return ans;
        
    }
};