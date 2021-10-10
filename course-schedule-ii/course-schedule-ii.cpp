class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            ans.push_back(q.front());
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        for(int i=0 ; i<numCourses ; i++) {
            if(indegree[i] != 0){
                return {};
            }
        }
        return ans;
    }
};