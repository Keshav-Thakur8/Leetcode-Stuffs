class Solution {
public:
    //Ouick Sort Approach
    void partition(vector<int>& nums, int pivot){
        int n = nums.size();
        for(int i=0,j=0 ; i<n ; i++){
            if(nums[i]<pivot){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
    void sortColors(vector<int>& nums) {
        int pivot = 1;
        partition(nums,pivot);
        pivot = 2;
        partition(nums,pivot);
        // int count_zero = 0;
        // int count_one = 0;
        // int len = nums.size();
        // for(int i=0 ; i<len ; i++){
        //     if(nums[i] == 0){
        //         count_zero++;
        //     }
        //     if(nums[i] == 1){
        //         count_one++;
        //     }
        // }
        // for(int i=0 ; i<count_zero ; i++){
        //     nums[i] = 0;
        // }
        // for(int i=count_zero ; i<(count_zero+count_one) ; i++){
        //     nums[i] = 1;
        // }
        // for(int i=(count_zero+count_one) ; i<len ; i++){
        //     nums[i] = 2;
        // }
    }
};