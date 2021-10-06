class Solution {
    bool validbox(int i, int j, vector<vector<char>>& board){
        unordered_set<char> s;
        for(int x = i; x<i+3; x++){
            for(int y = j; y<j+3; y++){
                if(board[x][y] != '.' and s.count(board[x][y])){
                    return false;
                }
                s.insert(board[x][y]);
            }        
       }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i = i+3){
            for(int j=0; j<9; j=j+3){
                if(!validbox(i,j,board)){
                    return false;
                }
            }
        }
        
        unordered_set<char> s;
        for(int i=0; i<9; i++){
            s.clear();
            for(int j=0; j<9; j++){
                if(board[i][j] != '.' and s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }
        
          for(int j=0; j<9; j++){
            s.clear();
            for(int i=0; i<9; i++){
                if(board[i][j] != '.' and s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }
 
        return true;
    }
};