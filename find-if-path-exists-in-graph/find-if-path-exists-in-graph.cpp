class Solution {
public:
    bool solve(vector<int> adj[], vector<bool> &visited, int start, int end) {
        if(start == end) {
            return true;
        }
        visited[start] = true;
        
        for(auto node : adj[start]) {
            if(!visited[node]) {
                if(solve(adj, visited, node, end)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> adj[n];
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n,false);
        return solve(adj, visited, start, end);
    }
};