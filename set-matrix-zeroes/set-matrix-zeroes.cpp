class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //TC: O(n*m + n*m)
        //SC: O(n+m)
        //create two vector : these vector will act as a marker for the row and column which is to marked 0
        //one with size of row
        // vector<int> v1(m,1);
        // //another with size of column
        // vector<int> v2(n,1);
        // //check for the position in matrix where we have zero
        // //and mark the corresponding i and j position in the two vectors
        // for(int i=0 ; i<m ; i++){
        //     for(int j=0 ; j<n ; j++){
        //         if(matrix[i][j] == 0){
        //             v1[i] = v2[j] = 0;
        //         }
        //     }
        // }
        // //once above is done
        // //we again check the matrix
        // //for any (i,j) we check the correspomding vector
        // //if any of i or j is zero we mark that (i,j) with 0
        // for(int i=0 ; i<m ; i++){
        //     for(int j=0 ; j<n ; j++){
        //         if(v1[i] == 0 || v2[j] == 0){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }
        
        //optimal solution
        //instead of taking two vectors, we can make 0th row and 0th column as a marker
        //this will save space
        //SC: O(1)
        int col0 = 1;
        for(int i=0 ; i<m ; i++){
            if(matrix[i][0] == 0)
                col0 = 0;
            for(int j=1 ; j<n ; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=1 ; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(col0 == 0)
                matrix[i][0] = 0;
        }
    }
};
