class Solution {
public:
    void solve(vector<vector<char>>& grid,int i,int j){
      int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int k=0;k<4;k++){
            int x = i+dx[k];
            int y = j+dy[k];
            solve(grid,x,y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
         int n = grid.size();
         int m = grid[0].size();
         int c=0;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(grid[i][j] == '1')
                   {
                     solve(grid,i,j);
                     c++;
                   }
             }
        }
        return c;
    }
};




//  int solve(){
//         int ans = 0;
//         queue<pair<int, int>> q;
//         int n = grid.size();
//         int m = grid[0].size();
//         int dx[] = {0,1,0,-1};
//         int dy[] = {1,0,-1,0};
//         for(int i=0 ; i<n ; i++) {
//             for(int j=0 ; j<m ; j++) {
//                 if(grid[i][j] == '1') {
//                     ans++;
//                     q.push({i,j});
//                     grid[i][j] = '0';
//                     while(!q.empty()) {
//                         pair<int, int> p = q.front();
//                         for(int i=0 ; i<4 ; i++) {
//                             int newX = p.first+dx[i];
//                             int newY = p.second+dy[i];
//                             if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY] == '1') {
//                                 grid[newX][newY] = '0';
//                                 q.push({newX,newY});
//                             }
//                         }
//                     }
//                 }
                
//             }
//         }
//         return ans;
//     }