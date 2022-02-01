class Solution {
public:
    int titleToNumber(string columnTitle) {
        long col_num = 0;
        //col_num = columnTitle[0]-'A'+1;
        for(int i=0; i<columnTitle.size(); i++){
            int d = columnTitle[i]-'A'+1;
            col_num = (col_num*26)+d;
        }
        
        return col_num;
    }
};
