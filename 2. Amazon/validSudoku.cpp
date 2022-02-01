class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
        set<string>s;
        
        string row, col, box;
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c]!='.'){
                    row = "row"+to_string(r)+board[r][c]; //for uniqe identification
                    col = "col"+to_string(c)+board[r][c];
                    box = "box"+to_string((r/3)*3+(c/3))+board[r][c];
                    
                    
                    int prev_size = s.size();
                    
                    s.insert(row), s.insert(col), s.insert(box);
                    
                    int after_size = s.size();
                    
                    if(prev_size+3!=after_size){
                        
                        return false;
                    }
                }
            }    
        }
        
        return true;
    }
};
