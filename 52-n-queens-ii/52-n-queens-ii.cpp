class Solution {
public:
    void solve(int col, vector<string>&board, int n, int &cnt, vector<int>&left,
               vector<int>&lowerDiagonal,vector<int>&upperDiagonal){
        if(col==n){
            cnt++;
            return;
        }
        for(int row=0; row<n; row++){
            if(left[row]==0 and lowerDiagonal[row+col]==0 and upperDiagonal[(n-1)+(col-row)]==0){
                board[row][col]='Q';
                left[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[(n-1)+(col-row)]=1;
                
                solve(col+1,board,n, cnt, left, lowerDiagonal, upperDiagonal);
                
                board[row][col]='.';
                left[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[(n-1)+(col-row)]=0;
            }
        }
    }
    
    int totalNQueens(int n) {
        string s(n,'.');
        vector<string>board(n);
        for(int i=0; i<n; i++){
            board[i]=s;
        }
        int cnt=0;
        vector<int>left(n);
        vector<int>lowerDiagonal(2*n-1);
        vector<int>upperDiagonal(2*n-1);
        
        solve(0,board,n,cnt,left,lowerDiagonal,upperDiagonal);
        return cnt;
    }
};