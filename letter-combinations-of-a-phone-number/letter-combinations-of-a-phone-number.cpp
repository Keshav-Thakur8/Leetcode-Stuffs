class Solution {
public:
    vector<string> map = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void solve(string &digits, int i, string op) {
        if(digits[i] == '\0') {
            ans.push_back(op);
            return ;
        }
        int curr_digit = digits[i]-'2';
        for(int k=0; k<map[curr_digit].size();k++){
		    solve(digits, i+1, op + map[curr_digit][k]);
	    }
	    return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") {
            return ans;
        }
        solve(digits, 0, "");
        return ans;
    }
};