class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //from the right, find the dip
        int n = nums.size(), i;
        
        if(n == 1) return ;
        
        for(i=n-2 ; i >= 0 && nums[i]>=nums[i+1] ; i--);
        
        int j=i;
        //if found a dip
        if(i>=0) {
            int j = i, k;
            //find the smallest number greater thean nums[j] to the right of j
            for(k=j+1 ; k<n && nums[k]>nums[j] ; k++);
                
            swap(nums[j],nums[k-1]);
        }
        //reverse nums[j+1...n-1]
        int k = j+1, l = n-1;
        while(k < l){
            swap(nums[k], nums[l]);
            k++;l--;
        }
    }
};