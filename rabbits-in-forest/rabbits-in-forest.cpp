class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int i : answers) {
            mp[i]++;
        }
        int ans = 0;
        for(auto i : mp) {
            ans += (i.first+i.second)/(i.first+1) * (i.first+1);
        }
        return ans;
    }
};