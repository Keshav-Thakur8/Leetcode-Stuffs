class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        vector<int> ans;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            int diff = target - nums[i];
            
            if(myMap.find(diff) != myMap.end()) {
                ans.push_back(myMap[diff]);
                ans.push_back(i);
                return ans;
            }
            myMap[nums[i]] = i;
        }
        return ans;
        
    }
};