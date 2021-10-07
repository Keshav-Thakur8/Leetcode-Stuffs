class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int start=0;
        int end=0;
        int result=1;
        int count=0;
        while(end<n){
            result*=nums[end];
            while(start<n and result>=k){
                result/=nums[start];
                start++;
            }
            if(result<k){
                count+=end-start+1;
            }
            end++;
        }
        return count;
        
    }
};