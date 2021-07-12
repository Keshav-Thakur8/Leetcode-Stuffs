class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        //find find the transpose
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<i ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //after finding transpose
        //reverse elements row wise
        for(int i=0 ; i<m ; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};