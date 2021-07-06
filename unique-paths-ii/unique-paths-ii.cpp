class Solution {
public:
    //Efficient DP Solution
    int path(vector<vector<int>>& obstacleGrid,int x, int y, int m, int n, vector<vector<int>>& dp){
        //Base Case
        if(x==m-1 && y==n-1){
            dp[x][y] = 1;
        }
        if(x<0 || x>=m || y<0 || y>=n || obstacleGrid[x][y] == 1){
            return 0;
        }
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        else{
            return dp[x][y] = path(obstacleGrid, x+1, y, m, n, dp)+path(obstacleGrid, x, y+1, m, n, dp);
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = path(obstacleGrid,0,0,m,n,dp);
        return ans;
    }
    //TLE backtracking solution
    // int ans = 0;
    // bool isSafe(vector<vector<int>>& obstacleGrid, int x, int y, int m, int n){
    //     if(x<m && y<n && obstacleGrid[x][y] == 0 && obstacleGrid[m-1][n-1] != 1){
    //         return true;
    //     }
    //     return false;
    // }
    // void path(vector<vector<int>>& obstacleGrid, int x, int y, int m, int n){
    //     //base case
    //     if((x == m-1 && y == n-1 && obstacleGrid[m-1][n-1] != 1)){
    //         ans++;
    //         return;
    //     }
    //     if(isSafe(obstacleGrid,x,y,m,n)){
    //         obstacleGrid[x][y]=1;
    //         path(obstacleGrid,x+1,y,m,n);
    //         path(obstacleGrid,x,y+1,m,n);
    //         obstacleGrid[x][y] = 0;
    //     }
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();
    //     path(obstacleGrid,0,0,m,n);
    //     return ans;
    // }
};