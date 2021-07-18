class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mp;
        int pos;
        int max_val = 0;
        //row by row
        for(int i=0 ; i<(int)wall.size() ; i++) {
            pos = 0;
            for(int j=0 ; j<(int)wall[i].size()-1 ; j++) {
                pos += wall[i][j];
                mp[pos]++;
                
                max_val = max(max_val, mp[pos]);
            }
        }
        return (int)wall.size()-max_val;
    }
};