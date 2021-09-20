class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    bool isValid(int x, int y, int m, int n) {
        if(x==m || y==n || x<0 || y<0) {
            return false;
        }
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j});
                    ans[i][j] = 0;
                    
                }
            }
        }
        while(!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for(auto& x : dir) {
                int a = curr.first + x[0];
                int b = curr.second + x[1];
                if(isValid(a,b,m,n) && ans[a][b] == -1) {
                    q.push({a,b});
                    ans[a][b] = ans[curr.first][curr.second] + 1;
                }
            }
        }
        return ans;
    }
};