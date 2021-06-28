class Solution {
public:
    int getSum(int i, int j, int len, vector<vector<int>>& prefix_sum) {
        int i_prime = i - len + 1;
        int j_prime = j - len + 1;
        
        int res = prefix_sum[i][j];
        
        if (j_prime - 1 >= 0)
            res -= prefix_sum[i][j_prime - 1];
        
        if (i_prime - 1 >= 0)
            res -= prefix_sum[i_prime - 1][j];
        
        if (i_prime - 1 >= 0 && j_prime - 1 >= 0)
            res += prefix_sum[i_prime - 1][j_prime - 1];
        
        return res;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // Preprocessing
        // Compute the prefix sum
        int m = mat.size(), n = mat[0].size(), i, j;
        vector<vector<int>> prefix_sum(m, vector<int>(n, 0));
        
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                // Interested in computing prefix_sum[i][j].
                prefix_sum[i][j] = mat[i][j];
                
                // Include (i-1, j)
                if (i - 1 >= 0)
                    prefix_sum[i][j] += prefix_sum[i - 1][j];
                
                // Include (i, j-1)
                if (j - 1 >= 0)
                    prefix_sum[i][j] += prefix_sum[i][j - 1];
                
                // Exclude (i-1, j-1)
                if (i - 1 >= 0 && j - 1 >= 0)
                    prefix_sum[i][j] -= prefix_sum[i - 1][j - 1];
            }
        }
        
        // Binary Search.
        // Try out all bottom-right corners.
        int max_res = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                // With (i, j) as the bottom right corner, find out the max length 
                // square with sum <= threshold. Use Binary Search for that.
                int lo = 1, hi = min(i, j) + 1, mid;
                while (lo < hi) {
                    mid = lo + (hi - lo + 1)/2;
                    
                    if (getSum(i, j, mid, prefix_sum) > threshold)
                        hi = mid - 1;
                    else
                        lo = mid;
                }
                
                // Sanity Check.
                if (getSum(i, j, lo, prefix_sum) <= threshold)
                    max_res = max(max_res, lo);
            }
        }
        
        return max_res;
        
    }
};