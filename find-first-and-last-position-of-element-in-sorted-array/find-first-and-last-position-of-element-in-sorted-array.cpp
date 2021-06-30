class Solution {
public:
    int upper_bound(vector<int>& nums, int target){
        int n = nums.size();
        int si = 0;
        int ei = n-1;
        int upIndex = -1;
        
        while(si <= ei){
            int mid = (si+ei)/2;
            if(nums[mid] == target){
                upIndex = mid;
                si = mid+1;
            }
            else if(nums[mid] > target){
                ei = mid-1;
            }
            else{
                si = mid+1;
            }
        }
        return upIndex;
    }
    
    int lower_bound(vector<int>& nums, int target){
        int n = nums.size();
        int si = 0;
        int ei = n-1;
        int lowIndex = -1;
        
        while(si <= ei){
            int mid = (si+ei)/2;
            if(nums[mid] == target){
                lowIndex = mid;
                ei = mid-1;
            }
            else if(nums[mid] > target){
                ei = mid-1;
            }
            else{
                si = mid+1;
            }
        }
        return lowIndex;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower_bound(nums, target);
        int high = upper_bound(nums, target);
        vector<int> ans;
        ans.push_back(low);
        ans.push_back(high);
        return ans;
        
        
    }
};