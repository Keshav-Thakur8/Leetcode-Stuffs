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
            //if the product is greater then k then divide the value at the start index from the given
            //array and increase the start
            while(start<n && product>=k){
                product /= nums[start];
                start++;
            }
            if(product < k){
                //tricky step
                cnt += end-start+1;
            }
            end++;
        }
        
        return cnt;
    }
};