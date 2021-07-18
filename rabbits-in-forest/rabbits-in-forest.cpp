class Solution {
public:
    //notes dekho
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int i=0 ; i<answers.size() ; i++) {
            mp[answers[i]]++;
        }
        int ans = 0;
        for(auto i : mp) {
            // ans += (i.first+i.second)/(i.first+1) * (i.first+1);
            int gs = i.first+1; // group size
            int reportees = i.second; // rabbit who report there types
            int ng = (i.second+i.first)/(i.first+1); //number of minimum groups required
            ans += ng*gs;
        }
        return ans;
    }
};
