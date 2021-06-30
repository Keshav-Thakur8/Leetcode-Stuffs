class Solution {
public:
    int ans = 0;
    //function to check is it safe to put queen in a particular place 
    bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
        //check upper diagonal
        int i = row;
        int j = col;
        while(row >= 0 && col >= 0){
            if(board[row][col] == '1') {
                return false;
            }
            row--;
            col--;
        }
        
        //check left side
        col = j;
        row = i;
        while(col >= 0) {
            if(board[row][col] == '1') {
                return false;
            }
            col--;
            
        }
        
        // check lower diagonal
        col = j;
        row = i;
        while(row < n && col >= 0){
            if(board[row][col] == '1') {
                return false;
            }
            row++;
            col--;
        }
        return true;
        
    }
    
    //Backtracking and recursion function
    void solver(int col, vector<vector<int>> &board, int n) {
        //Base Case
        if(col == n){
            ans++;
            return;
        }
        
        //Recursive Step
        for(int row = 0 ; row < n ; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = '1';
                solver(col+1, board, n);
                //Backtrack
                board[row][col] = '0';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> board( n , vector<int> (n, 0));
        solver(0,board,n);
        return ans;
        
    }
};