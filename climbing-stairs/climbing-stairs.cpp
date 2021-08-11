class Solution {
public:
    //top down
    int solve(int n, vector<int>& dp) {
        //base case
        if(n==1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        //if already encountered
        if(dp[n] != -1) {
            return dp[n];
        }
        //otherwise compute the value
        dp[n] = solve(n-1,dp) + solve(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n, dp);
        
        // //bottom up
        // vector<int> dp(n+1);
        // dp[1] = 1;
        // if(n == 1) {
        //     return dp[1];
        // }
        // dp[2] = 2;
        // for(int i=3 ; i<=n ; i++) {
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];
    }
};