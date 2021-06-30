class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            nums[i]--;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[0]*nums[1];
        //Two line solution
        // sort(nums.begin(), nums.end(), greater<int>());
        // return (nums[0]-1)*(nums[1]-1);
        
    }
};
