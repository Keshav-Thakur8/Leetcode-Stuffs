class Solution {
public:
    void solve(int n, int start, vector<bool> &visited, int &cnt) {
        if(start > n) {
            cnt++;
        }
        for(int i=1 ; i<=n ; i++) {
            if(!visited[i] && (start % i == 0 || i % start == 0)) {
                visited[i] = true;
                solve(n, start+1, visited, cnt);
                visited[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        int cnt = 0;
        vector<bool> visited(n+1, false);
        solve(n, 1, visited, cnt);
        return cnt;
        
    }
};