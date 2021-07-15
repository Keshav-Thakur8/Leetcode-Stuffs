class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            if(nums[abs(nums[i])] < 0)
                return abs(nums[i]);
            else
                nums[abs(nums[i])] *= -1;
        }
        // vector<bool> visited(n+1, false);
        // for(int i=0 ; i<n ; i++){
        //     if(visited[nums[i]] == true){
        //         return nums[i];
        //     }
        //     else{
        //         visited[nums[i]] = true;
        //     }
        // }
//         int n = nums.size();
//         int res = 0;
//         unordered_map<int, int> cnt;
//         for(int i=0 ; i<n ; i++){
//             cnt[nums[i]]++;
//         }
//         for(int i=0 ; i<n ; i++){
//             if(cnt[i]>=2)
//                 res = i;
            
//         }
//         return res;
        return -1;
        
    }
};