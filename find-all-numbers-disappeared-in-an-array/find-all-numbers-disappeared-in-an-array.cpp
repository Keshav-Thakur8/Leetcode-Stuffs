class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //optimized solution
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            int x = abs(nums[i])-1;
            nums[x] = nums[x]>0 ? -nums[x] : nums[x];
        }
        
        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        
        // unordered_map<int,int> m;
        // for(int i=0 ; i<nums.size() ; i++){
        //     m[nums[i]]++;
        // }
        // for(int i=1 ; i<=nums.size() ; i++){
        //     if(m[i] == 0){
        //         ans.push_back(i);
        //     }
        // }
        return ans;
    }
};
