class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [=](int a, int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        string ans = "";
        if(nums[0] == 0){
            return "0";
        }
        for(int i=0 ; i<nums.size() ; i++){
            ans  = ans + to_string(nums[i]);
        }
        return ans;
    }
};