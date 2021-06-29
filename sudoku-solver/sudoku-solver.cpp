class Solution {
public:
    //solver function
    bool solve(vector<vector<char>>& board) {
        for(int i=0 ; i<board.size() ; i++) {
            for(int j=0 ; j<board[0].size() ; j++) {
                //you can only proceed if the cell is empty
                if(board[i][j] == '.') {
                    for(char c='1' ; c<='9' ; c++) {
                        if(isSafe(board, i, j, c)) {
                            board[i][j] = c;
                            //recursive call
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //function to check if it is safe to put in that position
    bool isSafe(vector<vector<char>>& board, int row, int col, char c) {
        for(int i=0;i<9;i++) {
            //check column for safety
            if(board[i][col] == c) return false;
            //check row for safety
            if(board[row][i] == c) return false;
            //check grid for safety
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};