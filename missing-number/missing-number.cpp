class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Do the XOR of the index (from 0 to n ) with values of the array we will getting the required             answer, because the missing number will not have its pair!
        int missing_number = nums.size();
        for(int i=0 ; i<nums.size() ; i++){
            missing_number = missing_number^i^nums[i];
        }
        return missing_number;
        
    }
};