class Solution {
public:
    int solve(int n, vector<int> &dp) {
        //top down hai
        //base case
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }
    int fib(int n) {
        // if(n == 0) {
        //     return 0;
        // }
        // if(n == 1) {
        //     return 1;
        // }
        // return fib(n-1)+fib(n-2);
        vector<int> dp(n+1,-1);
        return solve(n, dp);
        
    }
};
