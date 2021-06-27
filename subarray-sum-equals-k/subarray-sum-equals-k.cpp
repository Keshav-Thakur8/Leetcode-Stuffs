class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        int len = nums.size();
        int curr_sum = 0, cnt = 0;
        
        for (int i = 0; i < len; i++) {
            curr_sum = curr_sum+nums[i];
            if(curr_sum-k == 0){
                cnt++;
            }
            if(myMap.find(curr_sum-k) != myMap.end()){
                cnt += myMap[curr_sum-k];
            }
            myMap[curr_sum]++;
        }
        return cnt;
        
    }
};