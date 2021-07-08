class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int si = 0;
        int ei = n-1;

        while(si <= ei){
            //for removing duplicates
            while (si < ei && nums[si] == nums[si + 1]){
                si++;
            }
            while (si < ei && nums[ei] == nums[ei - 1]){
                ei--;
            }
            //rest is same as search in rotated sorted array
            int mid = (si+ei)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[si]<=nums[mid]){
                if(target>=nums[si] && target<=nums[mid]){
                    ei = mid-1;
                }
                else{
                    si = mid+1;
                }
            }
            else{
                if(target>=nums[mid] && target<=nums[ei]){
                    si = mid+1;
                }
                else{
                    ei = mid-1;
                }
            }
        }

        return false;
    }
};
