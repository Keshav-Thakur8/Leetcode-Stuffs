class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long axorb = 0;
        //after this step you will have the xor of the numbers which you are searching
        for(int i=0 ; i<nums.size() ; i++){
            axorb ^= nums[i];
        }
//         //find mask corresponding to the first position from the right where the bit is set for axorb
//         long mask = (~axorb+1)&axorb;
//         //divide the list in two groups
//         //G1:1 at that pos
//         //G2:0 at that pos
//         int a=0, b=0;
//         for(int i=0 ; i<nums.size() ; i++){
//             if(mask&nums[i])
//                 a ^= nums[i];
//             else
//                 b ^= nums[i];
            
//         }
//         return {a,b};
        
        int cnt = 0;
        while(axorb) {
            if(axorb & 1) {
                break;
            }
            cnt++;
            axorb = axorb >> 1;
        }
        
        int xor1 = 0;
        int xor2 = 0;
        for(int i=0 ; i<nums.size() ; i++) {
            if(nums[i] & (1<<cnt)) {
                xor1 ^= nums[i];
            }
            else {
                xor2 ^= nums[i];
            }
        }
        return {xor1,xor2};
        
        
    }
};