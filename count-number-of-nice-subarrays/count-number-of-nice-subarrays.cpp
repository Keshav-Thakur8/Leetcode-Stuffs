class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0 ; i<n ; i++) {
            nums[i] = nums[i]%2;
        }
        unordered_map<int,int> mp;
        mp[0] = 1;
        int run_sum = 0;
        int ans = 0;
        for(int j=0 ; j<n ; j++) {
            run_sum += nums[j];
            if(mp.find(run_sum-k) != mp.end()) {
                ans += mp[run_sum-k];
            }
            mp[run_sum]++;
        }
        return ans;
    }
};