class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        int start = 0;
        int end = 0;
        int product = 1;
        int n = nums.size();
        while(end < n){
            product = product*nums[end];
            while(start<n && product>=k){
                product /= nums[start];
                start++;
            }
            if(product < k){
                cnt += end-start+1;
            }
            end++;
        }
        
        return cnt;
    }
};