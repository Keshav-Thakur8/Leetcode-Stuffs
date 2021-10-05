class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int zero_cnt = 0;
        int left = 0;
        
        //here size of window doesn't matter, the size of window will increase or decrease
        //depending upon the number of zeros in that window i.e if zero_cnt > k
        
        for(int right=0 ; right<n ; right++) {
            if(nums[right] == 0) {
                zero_cnt++;
            }
            while(zero_cnt > k) {
                if(nums[left] == 0) {
                    zero_cnt--;
                }
                left++;
            }
            
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};