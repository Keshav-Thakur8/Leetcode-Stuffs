class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        int n = people.size(), i, idx, min_ht = INT_MAX;
        vector<vector<int>> copy(people);
        
        for (i = 0; i < n; i++) {
            // For people[i...n-1], find out the smallest h s.t. k == 0.
            idx = -1, min_ht = INT_MAX;
            for (int j = i; j < n; j++) {
                if (people[j][1] == 0) {
                    if (people[j][0] < min_ht) {
                        min_ht = people[j][0];
                        idx = j;
                    }
                }
            }
            res.push_back(copy[idx]);
            swap(people[i], people[idx]);
            swap(copy[i], copy[idx]);
            
            // Update.
            for (int j = i+1; j < n; j++) {
                if (people[j][0] <= people[i][0])
                    people[j][1]--;
            }
        }
        
        return res;
        
    }
};