//recursive solution
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


//recursive with backtracking
class Solution {
public:
    //Its just that, in this solution I am passing a copy of string combi for each function call, while in backtracking     //solutions, the same string will be used all along without making any copy.
    vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void solve(string &digits, int i, string &op) {
        //base case
        if(digits[i] == '\0') {
            ans.push_back(op);
            return ;
        }
        //recursive step
        //int curr_digit = digits[i]-'2';
        for(auto &curr_digit : map[digits[i] - '0']){
            op.push_back(curr_digit);
            solve(digits, i+1, op);
            op.pop_back();
		    //solve(digits, i+1, op + map[curr_digit][k]);
	    }
	    return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") {
            return {};
        }
        string op = "";
        solve(digits, 0, op);
        return ans;
    }
};
