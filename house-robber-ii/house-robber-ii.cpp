class Solution {
public:
    int solve(vector<int>& nums, int si, int ei, vector<int>&dp) {
        //base case
        //only one house is there
        if(si == ei-1) {
            return nums[ei-1];
        }
        //no house to loot
        if(si == ei) {
            return 0;
        }
        //if already solved
        if(dp[si] != -1) {
            return dp[si];
        }
        //solve and store
        dp[si] = max(solve(nums, si+1, ei, dp), nums[si]+solve(nums, si+2, ei, dp));
        return dp[si];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        vector<int> dp(n+1, -1), dp1(n+1, -1);
        return max(solve(nums, 0, n-1, dp), solve(nums, 1, n, dp1));
    }
};