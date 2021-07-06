class Solution {
public:
    string ans = "";
    bool solve(vector<vector<char>>& board, string word, int i, int j){
        //Base Case
        if(ans == word){
            return true;
        }
        //if at any instance the size of the ans string becomes greater than the word string
        //we will return false(i.e we will remove unneccesary steps)
        //you can call this as pruning step
        if(ans.length()>=word.length()){
            return false;
        }
        //condition to move forward
        if(i>=0 && i<board.size() && j>=0 && j<board[0].size() && board[i][j] != '0'){
            char a = board[i][j];
            ans.push_back(a);
            //mark the visited pos with '0', this will make sure that you dont come here again if you
            //have got solution through this
            board[i][j] = '0';
            //4 directions
            //forward in row
            if(solve(board,word,i+1,j)){
                return true;
            }
            //backward in row
            if(solve(board,word,i-1,j)){
                return true;
            }
            //forward in column
            if(solve(board,word,i,j+1)){
                return true;
            }
            //backward in column
            if(solve(board,word,i,j-1)){
                return true;
            }
            //backtracking step
            //if non of the above evaluates to true then we put the character back to its position
            board[i][j] = a;
            //also remove from answer
            ans.pop_back();
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        //loop for taking board[i][j]
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                //we will only proceed if board[i][j] is equal to the first character of word string
                if(board[i][j] == word[0]){
                    if(solve(board,word,i,j))
                        return true;
                }
            }
        }
        return false;
    }
};