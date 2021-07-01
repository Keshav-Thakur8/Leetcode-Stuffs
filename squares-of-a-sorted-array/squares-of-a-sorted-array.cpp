class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        // for(int i=0 ; i<n ; i++){
        //     nums[i] *= nums[i];
        // }
        // sort(nums.begin(), nums.end());
        // return nums;
        //Optimized solution
        int si = 0;
        int ei = n-1;
        vector<int> res(n);
        for(int k=ei ; k>=0 ; k--){
            if(abs(nums[si]) > abs(nums[ei])){
                res[k] = nums[si]*nums[si];
                si++;
            }
            else {
                res[k] = nums[ei]*nums[ei];
                ei--;
            }
        }
        return res;
        
    }
};
