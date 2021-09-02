class Solution {
public:
    int solve(int amount, vector<int>& coins, vector<vector<int>> &dp, int index) {
        int n = coins.size();
        //base case
        if(n == index || amount < 0) {
            return 0;
        }
        if(amount == 0) {
            return 1;
        }
        
        //if already solved
        if(dp[index][amount] != -1) {
            return dp[index][amount];
        }
        
        //otherwise solve it
        dp[index][amount] = solve(amount-coins[index], coins, dp, index) + solve(amount, coins, dp, index+1);
        
        return dp[index][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+2, vector<int>(amount+2, -1));
        return solve(amount, coins, dp, 0);
    }
};