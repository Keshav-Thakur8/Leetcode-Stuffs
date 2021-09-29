class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int si = 0;
        int ei = n-1;
        int mid;
        while(si < ei){
            mid = si + (ei-si)/2;
            if(nums[si] < nums[ei]){
                return nums[si];
            }
            if(nums[mid] >= nums[si]){
                si = mid+1;
            }
            else{
                ei = mid;
            }
        }
        return nums[si];
        
        
        // while(si < ei){
        //     if(nums[si] < nums[ei]){
        //         return nums[si];
        //     }
        //     int mid = si + (ei-si)/2;
        //     //this condition will handel the case in which vector contains only two integers
        //     //and the second one is smaller ten the first element
        //     if(nums[mid] >= nums[si]){
        //         si = mid+1;
        //     }
        //     else{
        //         ei = mid;
        //     }
        // }
        // //when we have only element in the array
        // return nums[si];
    }
};