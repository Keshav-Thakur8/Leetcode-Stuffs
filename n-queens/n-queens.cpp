class Solution {
public:
    vector<vector<string>> ans;
    //function to check is it safe to put queen in a particular place 
    bool isSafe(int row, int col, vector<string> board, int n) {
        //check upper diagonal
        int i = row;
        int j = col;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }
        
        //check left side
        col = j;
        row = i;
        while(col >= 0) {
            if(board[row][col] == 'Q') {
                return false;
            }
            col--;
            
        }
        
        // check lower diagonal
        col = j;
        row = i;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q') {
                return false;
            }
            row++;
            col--;
        }
        return true;
        
    }
    
    //Backtracking and recursion function
    void solver(int col, vector<string> &board, int n) {
        //Base Case
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        //Recursive Step
        for(int row = 0 ; row < n ; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solver(col+1, board, n);
                //Backtrack
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');
        for(int i=0 ; i<n ; i++){
            board[i] = s;
        }
        solver(0, board, n);
        return ans;
        
        
    }
};