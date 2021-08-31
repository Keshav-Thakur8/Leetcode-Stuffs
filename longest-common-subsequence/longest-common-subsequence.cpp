class Solution {
public:
//     int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
//         int m = s1.size();
//         int n = s2.size();
//         //out of bound
//         if(i >= m || j >= n) {
//             return 0;
//         }
        
//         //if already solved
//         if(dp[i][j] != -1) {
//             return dp[i][j];
//         }
        
//         //otherwise calculate
//         if(s1[i] == s2[j]) {
//             dp[i][j] = max(dp[i][j], 1+solve(s1, s2, i+1, j+1, dp));
//             return dp[i][j];
//         }
//         dp[i][j] = max(dp[i][j], solve(s1, s2, i+1, j, dp));
//         dp[i][j] = max(dp[i][j], solve(s1, s2, i, j+1, dp));
        
//         return dp[i][j];
        
//     }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(1001, vector<int>(1001, -1));
        // return solve(text1, text2, 0, 0, dp);
        
        
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        for(int i=0 ; i<=m ; i++){
            for(int j=0 ; j<=n ; j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                    continue;
                } 
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
