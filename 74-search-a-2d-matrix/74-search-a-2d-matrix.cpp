class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int si = 0;
        int ei = n-1;
        while(si>=0 && ei>=0 && si<m && ei<n) {
            if(matrix[si][ei] == target) {
                return true;
            }
            else if(matrix[si][ei] > target) {
                ei--;
            }
            else{
                si++;
            }
        }
        return false;
    }
};