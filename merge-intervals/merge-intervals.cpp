class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //TC: O(nlogn)
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n == 0){
            return ans;
        }
        //sort on the basis of first index
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];
        for(auto it : intervals){
            if(it[0] <= temp[1]){
                temp[1] = max(it[1],temp[1]);
            }
            else{
                ans.push_back(temp);
                temp = it;
            }
        }
        //Take last interval also
        ans.push_back(temp);
        return ans;
    }
};