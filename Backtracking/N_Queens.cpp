class Solution {
public:
    bool canPlace(int row, int col, vector<string>& board){
        int n = board.size();
        int i = row, j = col;
        // up
        while(i >= 0){
            if(board[i][j] == 'Q') return false;
            i--;
        }
        // up left
        i = row;
        j = col;
        while(i >= 0 and j >= 0){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        // up right
        i = row;
        j = col;
        while(i >= 0 and j < n){
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void placeQueens(int row, vector<string>& board, vector<vector<string>>& ans){
        int n = board.size();
        if(row == n){
            vector<string> copy = board;
            ans.push_back(copy);
            return;
        }
        for(int j=0;j<n;j++){
            // board[row][j] me queen place karo if possible
            if(canPlace(row,j,board)){
                board[row][j] = 'Q';
                placeQueens(row+1,board,ans);
                board[row][j] = '.'; // backtracking
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        placeQueens(0,board,ans);
        return ans;
    }
};
