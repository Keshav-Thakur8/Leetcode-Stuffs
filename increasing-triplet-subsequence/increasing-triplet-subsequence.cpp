class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];
        int b = INT_MAX;
        for(int i=1 ; i<n ; i++){
            if(nums[i]<a){
                a=nums[i];
            }
            else if(nums[i]<b && nums[i]>a){
                b = nums[i];
            }
            else if(nums[i]>b){
                return true;
            }
        }
        return false;
        
    }
};