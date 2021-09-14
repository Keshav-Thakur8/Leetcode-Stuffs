class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        // for(int i=0 ; i<n ; i++) {
        //     for(int j=i+1 ; j<n ; j++) {
        //         if(nums[i] == nums[j]) {
        //             ans++;
        //         }
        //     }
        // }
        // return ans;
        
        unordered_map<int, int> mp;
        for(int i=0 ; i<n ; i++) {
            mp[nums[i]]++;
        }
        for(auto it : mp) {
            ans += (it.second * (it.second-1))/2;
        }
        return ans;
        
    }
};
