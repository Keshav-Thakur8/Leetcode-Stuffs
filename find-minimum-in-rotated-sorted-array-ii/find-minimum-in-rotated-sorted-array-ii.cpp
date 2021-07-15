class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int si = 0;
        int ei = n-1;
        int mid;
        while(si < ei){
            mid = si + (ei-si)/2;
            if(nums[mid] > nums[ei]){
                si = mid+1;
            }
            else if(nums[mid] < nums[ei]){
                ei = mid;
            }
            else{
                ei--;
            }
        }
        //when we have only element in the array
        return nums[si];
    }
};
