class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int si = 0;
        int ei = n;
        int mid;
        //this is the corner case in which our target should lie after the last element of nums
        //we will simply return the size of nums in this case
        if(target > nums[n-1]){
            return n;
        }
        //if the target should lie before the first element
        if(target < nums[0]){
            return 0;
        }
        while(si < ei) {
            mid = si+(ei-si)/2;
            if(nums[mid] == target){
                return mid;
            }
            //this condition will find the index in which target can be inserted
            else if(nums[mid]<target && nums[mid+1]>target){
                return mid+1;
            }
            else if(nums[mid] < target){
                si = mid+1;
            }
            else{
                ei = mid;
            }
        }
        return -1;
        
    }
};