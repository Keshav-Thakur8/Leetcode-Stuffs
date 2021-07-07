class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        int len = nums.size();
        int curr_sum = 0, cnt = 0;
        
        for (int i = 0; i < len; i++) {
            curr_sum = curr_sum+nums[i];
            int rem = curr_sum%k;
            if(rem == 0){
                cnt++;
            }
            if(rem < 0){
                rem += k;
            }
            if(myMap.find(rem) != myMap.end()){
                cnt += myMap[rem];
            }
            myMap[rem]++;
        }
        return cnt;
    }
};