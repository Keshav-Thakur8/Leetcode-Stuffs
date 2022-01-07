class Solution {
public:
    int upperBound(vector<int>& nums, int target) {
        int idx = -1;
        int si = 0;
        int ei = nums.size()-1;
        while(si <= ei) {
            int mid = si+(ei-si)/2;
            if(nums[mid] == target) {
                idx = mid;
                si = mid+1;
            }
            else if(nums[mid] < target) {
                si = mid+1;
            }
            else {
                ei = mid-1;
            }
        }
        return idx;
    }
    int lowerBound(vector<int>& nums, int target) {
        int idx = -1;
        int si = 0;
        int ei = nums.size()-1;
        while(si <= ei) {
            int mid = si+(ei-si)/2;
            if(nums[mid] == target) {
                idx = mid;
                ei = mid-1;
            }
            else if(nums[mid] > target) {
                ei = mid-1;
            }
            else {
                si = mid+1;
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int upIdx = upperBound(nums, target);
        int downIdx = lowerBound(nums, target);
        vector<int> ans;
        ans.push_back(downIdx);
        ans.push_back(upIdx);
        return ans;
    }
};