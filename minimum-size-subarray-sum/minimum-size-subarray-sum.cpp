class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int startpos = 0;
        int sum = 0;
        int min_length = INT_MAX;
        for(int i=0 ; i<nums.size() ; i++) {
            //prefix sum
            sum += nums[i];
            while(sum >= target) {
                min_length = min(min_length , i-startpos+1);
                //sliding window stuffs
                sum -= nums[startpos];
                startpos++;
            }
        }
        if(min_length == INT_MAX) {
            return 0;
        }
        return min_length;
    }
};