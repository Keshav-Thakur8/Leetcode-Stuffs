class Solution {
public:
    bool solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(board[i][j] != '.') {
                    char c = board[i][j];
                    board[i][j] = '.';
                    if(isSafe(board,i,j,c)) {
                        board[i][j] = c;
                        continue;
                    }
                    else{
                        return false;
                    } 
                }
            }
        }
        return true;
    }
    bool isSafe(vector<vector<char>>& board,int row,int col,char c) {
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
    bool isValidSudoku(vector<vector<char>>& board) {
         return solve(board);
    }
};