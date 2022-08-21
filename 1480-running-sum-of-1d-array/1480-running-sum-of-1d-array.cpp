class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int curr_sum = nums[0];
        for(int i=1 ; i<nums.size() ; i++) {
            nums[i] += curr_sum;
            curr_sum = nums[i];
        }
        return nums;
    }
};