class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //sort the array in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        if(n<3){
            return nums[0];
        }
        else if(nums[0] != nums[1] && nums[1] != nums[2]){
            return nums[2];
        }
        else{
            int cnt = 0;
            for(int i=0 ; i<n-1 ; i++){
                if(nums[i] != nums[i+1])
                    cnt++;
                if(cnt == 2)
                    return nums[i+1];
            }
            return nums[0];
        }
        return 0;
        
    }
};