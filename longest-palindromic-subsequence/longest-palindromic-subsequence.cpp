class Solution {
public:
    int solve(string &s, vector<vector<int>> &dp, int si, int ei) {
        //base case
        if(si > ei) {
            return 0;
        }
        if(si == ei) {
            return 1;
        }
        
        //if already solved
        if(dp[si][ei] != -1) {
            return dp[si][ei];
        }
        
        //solve if not already solved
        if(s[si] == s[ei]) {
            dp[si][ei] = 2 + solve(s, dp, si+1, ei-1);
        }
        else {
            dp[si][ei] = max(solve(s, dp, si, ei-1), solve(s, dp, si+1, ei));
        }
        
        return dp[si][ei];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n == 0) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solve(s, dp, 0, n-1);
    }
};