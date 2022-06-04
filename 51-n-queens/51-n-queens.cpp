class Solution {
public:
     
    void solve(int col,int n,vector<string>&board,vector<vector<string>>&ans,
               vector<int>&left,vector<int>&lowerDiagonal,vector<int>&upperDiagonal)
    {
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++){
            if(left[row]==0 and lowerDiagonal[row+col]==0 and upperDiagonal[(n-1)+(col-row)]==0){
                board[row][col] = 'Q';
                left[row]=1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                
                solve(col+1, n, board, ans, left, lowerDiagonal, upperDiagonal);
                
                board[row][col] = '.';
                left[row]=0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>board(n);
        vector<vector<string>>ans;
        vector<int>left(n);
        vector<int>lowerDiagonal(2*n-1);
        vector<int>upperDiagonal(2*n-1);
        for(int i=0;  i<n; i++){
            board[i] = s;
        }
        //cout<<"funCall"<<endl;
        solve(0,n,board,ans,left,lowerDiagonal,upperDiagonal);
        return ans;
    }
};