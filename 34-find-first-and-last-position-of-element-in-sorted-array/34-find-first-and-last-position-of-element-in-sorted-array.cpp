class Solution {
public:
    // for first occurence
    int lowerBound(vector<int>& nums, int target) {
        int idx = -1;
        int si = 0;
        int ei = nums.size()-1;
        int mid;
        while(si <= ei) {
            mid = si + (ei-si)/2;
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
    
    //for last occurence
    int upperBound(vector<int>& nums, int target) {
        int idx = -1;
        int si = 0;
        int ei = nums.size()-1;
        int mid;
        while(si <= ei) {
            mid = si + (ei-si)/2;
            if(nums[mid] == target) {
                idx = mid;
                si = mid+1;
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
        vector<int> ans;
        int first_pos = lowerBound(nums, target);
        int last_pos = upperBound(nums, target);
        ans.push_back(first_pos);
        ans.push_back(last_pos);
        
        return ans;
    }
};