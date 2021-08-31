class Solution {
public:
    int solve(vector<int>& nums, int i, int tot_sum, vector<vector<int>> &dp) {
        //base cases
        if(tot_sum == 0) {
            return 1;
        }
        if(i == nums.size() || tot_sum < 0) {
            return 0;
        }
      
        //if already computed
        if(dp[i][tot_sum] != -1) {
            return dp[i][tot_sum];
        }
        
        //otherwise compute
        dp[i][tot_sum] = solve(nums, i+1, tot_sum-nums[i], dp) || solve(nums, i+1, tot_sum, dp);
        return dp[i][tot_sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i:nums) {
            sum += i;
        }
        if(sum%2 != 0) {
            return false;
        }
        sum = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(nums, 0, sum, dp);
    }
};
