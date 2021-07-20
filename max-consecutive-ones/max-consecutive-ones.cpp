class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int max_size = 0;
        int cnt = 0;
        for(int i=0 ; i<n ; i++) {
            if(nums[i] == 0) {
                cnt = 0;
                continue;
            }
            else{
                cnt++;
            }
            max_size = max(max_size, cnt);
        }
        return max_size;
    }
};