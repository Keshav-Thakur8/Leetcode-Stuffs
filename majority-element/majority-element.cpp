class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        // for(int i=0 ; i<nums.size() ; i++){
        //     m[nums[i]]++;
        // }
        int occurence = nums.size()/2;
        for(int i=0 ; i<nums.size() ; i++){
            if(++m[nums[i]] > occurence){
                return nums[i];
            }
        }
        return 0;
        
        
    }
};
