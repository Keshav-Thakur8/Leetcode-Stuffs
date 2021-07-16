class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Brute Force
        sort(nums.begin(),nums.end());
        int cnt = 0, ans = 0;
        if(nums.size() == 0){
            return 0;
        }
        for(int i=0 ; i<nums.size()-1 ; i++){
            if(nums[i] == nums[i+1]-1){
                cnt++;
                ans = max(cnt,ans);
            }
            else if(nums[i] == nums[i+1]){
                continue;
            }
            else{
                cnt = 0;
            }
        }
        return ans+1;
    }
};