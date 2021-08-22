class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) {
            return n;
        }
        int cnt = 1, j = 1;
        for(int i=1 ; i<n ; i++) {
            if(nums[i-1] == nums[i]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            
            if(cnt <= 2) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};