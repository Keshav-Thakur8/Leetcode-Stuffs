class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp){
        //Base Case:Robot reached end point
        if(i==m-1 && j==n-1){
            return 1;
        }
        //if robot goes outer of border
        if(i>=m || j>=n){
            return 0;
        }
        //this will stop time consuming step
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        else {
            return dp[i][j] = countPaths(i+1,j,m,n,dp)+countPaths(i,j+1,m,n,dp);
        }
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(0,0,m,n,dp);
        
    }
};