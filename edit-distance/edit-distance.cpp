class Solution {
public:
    int solve(string &s1, string &s2, vector<vector<int>> &dp, int m, int n) {
        //base case
        //if first string is empty then insert all elements of second string into first
        //which will eventually be size of second string
        //vice versa for second statement
        if(m == 0) return n;
        if(n == 0) return m;
        
        //if already solved
        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        
        //if not, then compute it
        if(s1[m-1] == s2[n-1]) {
            dp[m][n] = solve(s1, s2, dp, m-1, n-1);
            return dp[m][n];
        }
        dp[m][n] = 1 + min(solve(s1, s2, dp, m-1, n-1), min(solve(s1, s2, dp, m, n-1), solve(s1, s2, dp, m-1, n)));
        
        return dp[m][n] == -1 ? 0 : dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return solve(word1, word2, dp, m, n);
        //return dp[m][n];
    }
};