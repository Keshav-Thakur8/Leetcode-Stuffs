class Solution {
public:
    int mod = (1e9) + 7;
    int countVowelPermutation(int n) {
        vector<long> dp(5, 0); //a=0, e=1, i=2, o=3, u=4
        for(int i = 0 ; i < 5 ; i++)
            dp[i] = 1;
        for(int i = 1 ; i < n ; i++){
            vector<long> temp(5, 0);
            temp[0] = (dp[1] + dp[2] + dp[4]) % mod;
            temp[1] = (dp[0] + dp[2]) % mod;
            temp[2] = (dp[1] + dp[3]) % mod;
            temp[3] = (dp[2]) % mod;
            temp[4] = (dp[2] + dp[3]) % mod;
            dp = temp;
        }
        int sum = 0;
        for(int i = 0 ; i < 5 ; i++)
            sum = (sum + dp[i]) % mod;
        return (int) sum;
    }
};