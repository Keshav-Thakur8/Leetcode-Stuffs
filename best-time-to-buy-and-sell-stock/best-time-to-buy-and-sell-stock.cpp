class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minDiff = prices[0];
        int profit = 0;
        int ans = 0;
        for(int i=1 ; i<n ; i++){
            profit = prices[i] - minDiff;
            minDiff = min(minDiff, prices[i]);
            ans = max(ans, profit);
            
        }
        return ans;
        
    }
};