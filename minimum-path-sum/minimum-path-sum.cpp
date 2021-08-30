class Solution {
public:
    int solve_dp(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        int m = grid.size();
        int n = grid[0].size();
        
        //if i and j is out of bound
        if(i >= m || j >= n) {
            return INT_MAX;
        }
        
        //if only one cell is there
        if(i == m-1 && j == n-1) {
            return grid[i][j];
        }
        
        //if already calculated
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        //otherwise calculate it
        dp[i][j] = grid[i][j] + min(solve_dp(grid, i+1, j, dp), solve_dp(grid, i, j+1, dp));
        
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve_dp(grid, 0, 0, dp);
    }
};