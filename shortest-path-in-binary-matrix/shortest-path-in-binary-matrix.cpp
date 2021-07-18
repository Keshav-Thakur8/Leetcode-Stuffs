class Solution {
public:
    //function for checking the existence of path
    bool isSafe(int x, int y, int m, int n, vector<vector<int>>& grid) {
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y] == 1) {
            return false;
        }
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //vector to store all 8 possible direction
        vector<vector<int>> moves = {{-1,-1},{1,0},{0,1},{-1,0},{0,-1},{1,-1},{-1,1},{1,1}};
        //if starting or ending is blocked, then its impossible to find the path
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) {
            return -1;
        }
        //queue of vector to keep track of path
        queue<vector<int>> q;
        //initially insert the starting index(i.e top left corner) and keep count to 1
        q.push({0,0,1});
        //perform operation till queue is not empty
        while(!q.empty()) {
            vector<int> fnt = q.front();
            q.pop();
            //The Fastest path is always the shortest path in BFS 
		    //hence,the first path to reach the destination is the shortest path.
            //check if we have reached the destination
            if(fnt[0]==m-1 && fnt[1]==n-1) {
                return fnt[2];
            }
            //move in 8 directions
            for(vector<int> dir : moves) {
                int x = fnt[0]+dir[0];
                int y = fnt[1]+dir[1];
                if(isSafe(x,y,m,n,grid)) {
                    //mark as visited
                    grid[x][y] = 1;
                    q.push({x,y,fnt[2]+1});
                }
            }
        }
        return -1;
    }
};