class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int len = nums.size();
        int temp = 1;
        for(int i=0 ; i<len ; i++){
            temp = temp*nums[i];
            output.push_back(temp);
        }
        temp = 1;
        for(int i=len-1 ; i>0 ; i--){
            output[i] = output[i-1]*temp;
            temp = temp*nums[i];
        }
        output[0] = temp;
        return output;
        
    }
};