class Solution {
public:
    vector<string> res;
    void helper(string s, int n, int open, int close){
        //Base Case
        if(open==n && close==n){
            res.push_back(s);
            return;
        }
        if(open<n){
            helper(s+'(',n,open+1,close);
        }
        if(close<open){
            helper(s+')',n,open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        helper(s,n,0,0);
        return res;
        
    }
};