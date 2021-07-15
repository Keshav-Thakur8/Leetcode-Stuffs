class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int si = 0;
        int ei = n-1;
        while(si < ei){
            if(nums[si] < nums[ei]){
                return nums[si];
            }
            int mid = si + (ei-si)/2;
            if(nums[mid] >= nums[si]){
                si = mid+1;
            }
            else{
                ei = mid;
            }
        }
        return nums[si];
    }
};