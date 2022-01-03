class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        // one triangle is *left* to antoher
        if(rec1[2]<=rec2[0]  || rec[2]<=rec1[0]){
            return false;
        }
        
        // one triangle is *above* another
        if(rec1[3]<=rec2[1] || rec2[3]<=rec1[1]){
            return false;
        }
        
        return true;
    }
};
