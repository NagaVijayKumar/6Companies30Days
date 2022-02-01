class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                
                //If it is empy cell try to fill value
                if(board[i][j ]== '.'){
                    
                    for(char ch = '1'; ch<='9'; ch++){
                        
                        if(isValid(board,i,j,ch)){
                            
                            board[i][j] = ch;
                            
                            //if it is a valid char to put, then go and fill other cells too
                            // solve(board);
                            
                            
                            //in the recursive calls, if it return true, then return true, 
                            // else our prev filling was wrong, so remove it
                            if(solve(board)==true){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    
                    // non of the number is fit in given gap, so we are here, so return false, (it effects in line 23)
                    return false;
                }
            }
        }
        
        // we are not getting any empty cells, so we are here, return true;
        return true;
    }
    
    
    //to check is valid, to put char in a particular position
    
    bool isValid(vector<vector<char>>& board, int r, int c, char ch){
        
        for(int i=0; i<9; i++){
            
             //row check
            if(board[r][i]==ch){
                return false;                
            }
            
            //col check
            if(board[i][c]==ch){
                return false;
            }
            
            //box check
            if(board[3 * (r/3) +i/3][3 * (c/3) + i%3] == ch){
                return false;
            }
        }
        
        return true;
    }
};
