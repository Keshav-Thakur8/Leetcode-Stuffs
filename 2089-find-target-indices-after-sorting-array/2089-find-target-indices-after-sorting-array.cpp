class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0 ; i<nums.size() ; i++) {
            if(nums[i] == target) {
                ans.push_back(i);
            }
        }
        return ans;
        // int si = 0;
        // int ei = nums.size()-1;
        // while(si <= ei) {
        //     int mid = si + (ei-si)/2;
        //     if(nums[mid] == target) {
        //         ans.push_back(mid);
        //         ei = mid-1;
        //     }
        //     else if(nums[mid] > target) {
        //         ei = mid-1;
        //     }
        //     else {
        //         si = mid+1;
        //     }
        // }
        // sort(ans.begin(), ans.end());
        // return ans;
    }
};