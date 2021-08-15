class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp solution
        int n = nums.size();
        int ans = INT_MIN;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        ans = dp[0];
        for(int i=1 ; i<n ; i++) {
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
            ans = max(ans, dp[i]);
        }
        return ans;
        
        // int max_so_far = nums[0];
        // int curr_max = nums[0];
        // for(int i=1 ; i<n ; i++){
        //     curr_max = max(nums[i], curr_max+nums[i]);
        //     max_so_far = max(max_so_far, curr_max);
        //     // max_ending_here += nums[i];
        //     // if(max_ending_here > max_so_far){
        //     //     max_so_far = max_ending_here;
        //     // }
        //     // if(max_ending_here < 0){
        //     //     max_ending_here = 0;
        //     // }
        // }
        // return max_so_far;
        
    }
};