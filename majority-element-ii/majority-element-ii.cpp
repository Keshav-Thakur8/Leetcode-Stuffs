class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //hashmap approach
        unordered_map<int,int> m;
        int n = nums.size();
        vector<int> ans;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
        }
        for(auto it : m){
            if(it.second > n/3)
                ans.push_back(it.first);
        }
        return ans;
    }
};