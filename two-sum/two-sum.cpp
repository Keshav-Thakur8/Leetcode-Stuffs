class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            int diff = target - nums[i];
            
            if(myMap.count(diff)) 
                return { myMap[diff], i };
            myMap[nums[i]] = i;
        }
        return {};
        
    }
};