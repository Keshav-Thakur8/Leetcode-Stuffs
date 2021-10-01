class Solution {
public:
    void solve(vector<vector<int>>& graph, vector<bool>& visited, int start) {
        visited[start] = true;
        for(int i=0 ; i<(int)graph.size() ; i++) {
            if(graph[start][i] && !visited[i]) {
                solve(graph, visited, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;
        vector<bool> visited(n, false);
        for(int i=0 ; i<n ; i++) {
            if(!visited[i]) {
                res++;
                solve(isConnected, visited, i);
            }
        }
        return res;
    }
};