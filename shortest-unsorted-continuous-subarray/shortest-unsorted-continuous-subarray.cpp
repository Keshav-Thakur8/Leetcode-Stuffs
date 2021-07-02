class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return 0;
        }
        int left = 0;
        int right = n-1;
        while(left<n-1 && nums[left]<=nums[left+1]){
            left++;
        }
        if(left == n-1){
            return 0;
        }
        while(nums[right]>=nums[right-1]){
            right--;
        }
        int minval = INT_MAX;
        int maxval = INT_MIN;
        for(int i=left ; i<=right ; i++){
            if(nums[i]<minval){
                minval = nums[i];
            }
            if(nums[i]>maxval){
                maxval = nums[i];
            }
        }
        while(left>=0 && nums[left]>minval){
            left--;
        }
        while(right<n && nums[right]<maxval){
            right++;
        }
        return right-left-1;
        
    }
};