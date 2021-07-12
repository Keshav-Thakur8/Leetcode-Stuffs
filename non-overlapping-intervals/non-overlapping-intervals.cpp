class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b) {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int cnt = -1;
        //int e=intervals[0][1];
        vector<int> temp = intervals[0];
        for(auto it : intervals){
            if(it[0] < temp[1]){
                cnt++;
            }
            else{
                temp = it;
            }
        }
        // for(int i=1; i<intervals.size(); i++)
        // {
        //     if(intervals[i][0]<e)
        //         cnt++;
        //     else
        //         e = intervals[i][1];
        // }
        return cnt;
    }
};