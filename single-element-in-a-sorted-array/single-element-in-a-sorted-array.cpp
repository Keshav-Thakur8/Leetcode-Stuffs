class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //binary search approach
        int n = nums.size();
        int si = 0;
        int ei = n-1;
        while(si <= ei){
            int mid = si+(ei-si)/2;
            //if mid is the answer
            if((mid==0 || nums[mid] != nums[mid-1]) && (mid==n-1 || nums[mid] != nums[mid+1]))
                return nums[mid];
            
            //if mid is not the answer
            if(nums[mid] == nums[mid-1]){
                if(mid%2==1)
                    si=mid+1;
                else
                    ei=mid-1;
            }
            else{
                if(mid%2==1)
                    ei=mid-1;
                else
                    si=mid+1;
            }
        }
        return -1;
        
        // //xor approach
        // int n = nums.size();
        // int res = 0;
        // for(int i=0 ; i<n ; i++){
        //     res ^= nums[i];
        // }
        // return res;
        
    }
};