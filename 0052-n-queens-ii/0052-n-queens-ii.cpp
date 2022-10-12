class Solution {
  int count = 0;
  private: bool isSafe(int row, int col, vector<vector<int>>board){
        for(int i=0;i<col;i++){
          if(board[row][i]){
            return false;
          }
        }
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
          if(board[i][j]){
            return false;
          }
        }
        for(int i=row, j=col; i<board.size() && j>=0; i++, j--){
          if(board[i][j]){
            return false;
          }
        }
        return true;
      }
  
  private: void totalQueensDriver(vector<vector<int>>board, int col = 0){
        if(col == board.size()) {
          cout<<col<<" "<<board.size()<<" "<<"hi";
          count++;
          return;
        };
        for(int i=0; i<board.size(); i++){
          if(isSafe(i,col,board)){
            board[i][col] = 1;
            totalQueensDriver(board, col+1);
            board[i][col] = 0;
          }
        }
        return;
      }
public:
    int totalNQueens(int n) {
      vector<vector<int>>board(n, vector<int>(n, 0));
      totalQueensDriver(board);
      return count;
    }
};