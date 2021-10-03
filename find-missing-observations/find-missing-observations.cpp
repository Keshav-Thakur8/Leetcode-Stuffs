class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int full_size = m+n;
        int roll_sum = 0;
        for(int i=0 ; i<m ; i++) {
            roll_sum += rolls[i];
        }
        int missing_sum = (mean*full_size)-roll_sum;
        if(missing_sum > n*6 || missing_sum < n) {
            return {};
        }
        int mod = missing_sum%n;
        vector<int> ans(n, missing_sum/n);
        for(int i=0 ; i<mod ; i++) {
            ans[i] += 1;
        }
        return ans;
    }
};