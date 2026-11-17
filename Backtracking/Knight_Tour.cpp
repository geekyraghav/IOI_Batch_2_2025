class Solution {
  public:
    void tour(int row, int col, int i, vector<vector<int>>& board, vector<vector<int>>& ans){
        int n = board.size();
        if(row < 0 or col < 0 or row >= n or col >= n or board[row][col] != -1) return;
        if(i == n*n-1){
            board[row][col] = i++;
            ans = board;
            return;
        }
        if(ans.size() == n) return; // IMPORTANT
        board[row][col] = i++;
        tour(row-2,col+1,i,board,ans); // up right
        tour(row-2,col-1,i,board,ans); // up left
        tour(row+2,col+1,i,board,ans); // down right
        tour(row+2,col-1,i,board,ans); // down left
        tour(row-1,col+2,i,board,ans); // right up
        tour(row+1,col+2,i,board,ans); // right down
        tour(row-1,col-2,i,board,ans); // left up
        tour(row+1,col-2,i,board,ans); // left down
        board[row][col] = -1;
    }
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> board(n,vector<int>(n,-1));
        vector<vector<int>> ans;
        tour(0,0,0,board,ans);
        return ans;
    }
};
