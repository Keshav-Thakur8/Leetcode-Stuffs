class Solution {
public:
    int helper(string &s, string &t, vector<vector<int>> &dp, int i, int j) {
        int m = s.size();
        int n = t.size();
        
        //base case
        if(j == n) {
            return 1;
        }
        if(i == m) {
            return 0;
        }
        
        //if already solved
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        //otherwise calculate
        if(s[i] == t[j]) {
            dp[i][j] = helper(s, t, dp, i+1, j+1) + helper(s, t, dp, i+1, j);
        }
        else {
            dp[i][j] = helper(s, t, dp, i+1, j);
        }
        
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(s, t, dp, 0, 0);
    }
};