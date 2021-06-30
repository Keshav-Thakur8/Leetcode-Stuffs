class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,j=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
//         int n = nums.size();
//         int si = 0;
//         int ei = n-1;
//         while(si < ei){
//             if(nums[si] == val){
//                 swap(nums[si], nums[ei]);
//                 si++;
//                 ei--;
//             }else{
//                 si++;
//             }
            
//         }
        
    }
};