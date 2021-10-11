class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int startPos = 0;
        int sum = 0;
        int minLen = INT_MAX;
        for(int i=0 ; i<nums.size() ; i++) {
            sum += nums[i];
            while(sum >= target) {
                minLen = min(minLen, i-startPos+1);
                sum -= nums[startPos];
                startPos++;
            }
        }
        if(minLen == INT_MAX) {
            return 0;
        }
        return minLen;
    }
};