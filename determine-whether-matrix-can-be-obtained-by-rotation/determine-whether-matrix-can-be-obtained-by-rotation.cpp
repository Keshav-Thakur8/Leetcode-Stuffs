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
        
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        //we will rotate max 4 times
        //because after 4 rotation of 90 degree we will get the initial matrix
        //so if in between 4 rotation we are getting the target then its fine
        //otherwise its not possible
        for(int i=0 ; i<4 ; i++){
            rotate(mat);
            if(mat == target)
                return true;
        }
        return false;
    }
};