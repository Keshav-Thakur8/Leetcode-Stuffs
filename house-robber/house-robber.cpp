class Solution {
public:
//     int solve(vector<int>& nums, int i, vector<int>& dp) {
//         //top-down
//         int n = nums.size();
//         //base case
//         //only one house is there
//         if(i == n-1) {
//             return nums[i];
//         }
//         // no house to loot
//         if(i == n) {
//             return 0;
//         }
        
//         //if already solved
//         if(dp[i] != -1) {
//             return dp[i];
//         }
//         dp[i] = max(solve(nums, i+1, dp), nums[i]+solve(nums, i+2, dp));
        
//         return dp[i];
//     }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        
        //return solve(nums, 0, dp);
        
        //bottom up
        dp[n-1] = nums[n-1];
        dp[n] = 0;
        
        for(int i=n-2 ; i>=0 ; i--) {
            dp[i] = max(dp[i+1], nums[i]+dp[i+2]);
        }
        
        return dp[0];
    }
};