class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();
        
        queue<pair<int,int>> q;
        q.push({start[0], start[1]});
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        vis[start[0]][start[1]] = true;
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x == destination[0] && y == destination[1]) {
                return true;
            }
            
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0 ; i<4 ; i++) {
                int newX = x;
                int newY = y;
                
                while(newX>=0 && newX<n && newY>=0 && newY<m && maze[newX][newY]==0) {
                    newX += dx[i];
                    newY += dy[i];
                }
                newX -= dx[i];
                newY -= dy[i];
                
                if(vis[newX][newY] == false){
                    vis[newX][newY] = true;
                    q.push({newX,newY});
                }
                
            }
        }
        return false;
    }
};