class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = 0;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            if(jump < 0){
                return false;
            }
            jump = max(jump, nums[i])-1;
        }
        return true;
        
    }
};