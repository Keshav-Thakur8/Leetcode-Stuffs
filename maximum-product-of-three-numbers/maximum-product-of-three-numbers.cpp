class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int t1 = nums[n-1]*nums[n-2]*nums[n-3];
        int t2 = nums[0]*nums[1]*nums[n-1];
        if(t1 > t2){
            return t1;
        }
        else {
            return t2;
        }
        return 0;
    }
};