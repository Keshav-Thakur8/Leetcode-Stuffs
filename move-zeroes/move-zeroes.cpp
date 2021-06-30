class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int si = 0;
        int ei = 0;
        while(ei < n){
            if(nums[ei] != 0){
                swap(nums[si], nums[ei]);
                si++;
            }
            ei++;
        }
        
        
    }
};