class Solution {
public:
    bool isSafe(int x, int y, int m, int n, vector<vector<int>>& grid) {
        if(x>=m || x<0 || y>=n || y<0 || grid[x][y]!=1) {
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //number of fresh orange
        int fresh = 0;
        int time = -1;
        //queue to store pairs of coordinates
        queue<vector<int>> q;
        //4 direction move
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                //count of valid oranges
                if(grid[i][j] > 0)
                    fresh++;
                //only rotten oranges must be on initial step of queue
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        
        //breadth first search
        while(!q.empty()){
            //one step from rotten
            time++;
            int queuesize = q.size();
            for(int k=0 ; k<queuesize ; k++){
                //take node from front of queue
                vector<int> curr = q.front();
                //decrese fresh orange count
                fresh--;
                q.pop();
                //look in all four direction
                for(int i=0 ; i<4 ; i++){
                    //record the coordinates
                    int x_cor = curr[0]+dir[i][0];
                    int y_cor = curr[1]+dir[i][1];
                    //if we go out of order or find orange which is not fresh
                    if(!isSafe(x_cor, y_cor, m, n, grid))
                        continue;
                    //orange kharab ho gaya
                    grid[x_cor][y_cor] = 2;
                    //coordinates of rotten orange
                    q.push({x_cor,y_cor});
                }
            }
        }
        //if we looked through all oranges, return result, else -1
        //here max(0,time) is for case [[0]] as input
        if(fresh==0) return max(0,time);
        return -1;
    }
};