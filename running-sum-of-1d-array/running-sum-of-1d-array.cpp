class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int curr_sum = nums[0];
        for(int i=0 ; i<n-1 ; i++){
            nums[i] = curr_sum;
            curr_sum += nums[i+1];
        }
        nums[n-1] = curr_sum;
        return nums;
        
    }
};