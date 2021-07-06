class Solution {
public:
    int ans = 0;
    void path(vector<vector<int>>& grid, int m, int n, vector<vector<bool>> visited, int x, int y, int cnt){
        //if we got the final solution
        if(cnt == -1 && grid[x][y] == 2){
            ans++;
            return;
        }
        //if all empty squares has been walked but we still didn't reached ending square
        //invalid solution
        if(cnt == -1 && grid[x][y] != 2){
            return;
        }
        //if we have still empty squares and we have reached ending square
        //invalid solution
        if(cnt>0 && grid[x][y] == 2){
            return;
        }
        //mark path taken as visited
        visited[x][y] = true;
        //4 direction
        //Forward in row
        if(x+1<m && visited[x+1][y] == false){
            path(grid,m,n,visited,x+1,y,cnt-1);
        }
        //Backward in row
        if(x-1>=0 && visited[x-1][y] == false){
            path(grid,m,n,visited,x-1,y,cnt-1);
        }
        //Forward in column
        if(y+1<n && visited[x][y+1] == false){
            path(grid,m,n,visited,x,y+1,cnt-1);
        }
        //Backward in column
        if(y-1>=0 && visited[x][y-1] == false){
            path(grid,m,n,visited,x,y-1,cnt-1);
        }
        //Backtracking Step: restore for next solution
        visited[x][y] = false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int zero_cnt = 0;
        int x=0, y=0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                //if obstacle:mark as visited
                if(grid[i][j] == -1){
                    visited[i][j] = true;
                }
                //store the count of empty square
                if(grid[i][j] == 0){
                    zero_cnt++;
                }
                //get the starting square
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
            }
        }
        path(grid, m, n, visited, x, y, zero_cnt);
        return ans;
    }
};