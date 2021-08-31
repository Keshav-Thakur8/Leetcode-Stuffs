class Solution {
public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        int m = s1.size();
        int n = s2.size();
        //out of bound
        if(i >= m || j >= n) {
            return 0;
        }
        
        //if already solved
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        //otherwise calculate
        if(s1[i] == s2[j]) {
            dp[i][j] = max(dp[i][j], 1+solve(s1, s2, i+1, j+1, dp));
            return dp[i][j];
        }
        dp[i][j] = max(dp[i][j], solve(s1, s2, i+1, j, dp));
        dp[i][j] = max(dp[i][j], solve(s1, s2, i, j+1, dp));
        
        return dp[i][j];
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};