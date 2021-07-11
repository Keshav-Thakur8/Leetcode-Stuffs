class Solution {
public:
    //function to check if the move is safe or not
    bool isSafe(int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n){
            return false;
        }
        return true;
    }
    
    //function to check if we have reached the exit cell
    bool isExit(int i, int j, int m, int n){
        if(i!=0 && j!=0 && i!=m-1 && j!=n-1){
            return false;
        }
        return true;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<vector<int>> q;
        q.push({0,entrance[0], entrance[1]});
        int x, y;
        int min_dist;
        vector<vector<bool>> visited(m,vector<bool>(n, false));
        while(!q.empty()){
            vector<int>f = q.front();
            x = f[1];
            y = f[2];
            min_dist = f[0];
            q.pop();
            //if we have reached exit
            if(isExit(x,y,m,n)){
                if(entrance[0] != x || entrance[1] != y)
                    return min_dist;
            }
            //4 direction traversal
            //down
            if(isSafe(x+1,y,m,n) && visited[x+1][y] == false && maze[x+1][y] != '+'){
                visited[x+1][y] = true;
                q.push({min_dist+1,x+1,y});
            }
            //up
            if(isSafe(x-1,y,m,n) && visited[x-1][y] == false && maze[x-1][y] != '+'){
                visited[x-1][y] = true;
                q.push({min_dist+1,x-1,y});
            }
            //right
            if(isSafe(x,y+1,m,n) && visited[x][y+1] == false && maze[x][y+1] != '+'){
                visited[x][y+1] = true;
                q.push({min_dist+1,x,y+1});
            }
            //left
            if(isSafe(x,y-1,m,n) && visited[x][y-1] == false && maze[x][y-1] != '+'){
                visited[x][y-1] = true;
                q.push({min_dist+1,x,y-1});
            }
        }
        return -1;
    }
};