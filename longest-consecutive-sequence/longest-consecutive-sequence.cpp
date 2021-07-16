class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //optimal solution
        set<int> hash;
        //insert elements of nums into the set
        for(int i=0 ; i<nums.size() ; i++){
            hash.insert(nums[i]);
        }
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            //for every element in the vector check if one lesser then it exist or not
            //if it exists do nothing
            //otherwise start moving one step ahead of that number till you encounter final value
            //then check if it is maximum or not
            if(!hash.count(nums[i]-1)){
                int curr_num = nums[i];
                int curr_cnt = 1;
                while(hash.count(curr_num+1)){
                    curr_num += 1;
                    curr_cnt++;
                }
                ans = max(ans,curr_cnt);
            }
        }
        return ans;
        // //Brute Force
        // sort(nums.begin(),nums.end());
        // int cnt = 0, ans = 0;
        // if(nums.size() == 0){
        //     return 0;
        // }
        // for(int i=0 ; i<nums.size()-1 ; i++){
        //     if(nums[i] == nums[i+1]-1){
        //         cnt++;
        //         ans = max(cnt,ans);
        //     }
        //     else if(nums[i] == nums[i+1]){
        //         continue;
        //     }
        //     else{
        //         cnt = 0;
        //     }
        // }
        // return ans+1;
    }
};
