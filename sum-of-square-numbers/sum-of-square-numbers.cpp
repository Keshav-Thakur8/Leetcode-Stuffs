class Solution {
public:
    bool judgeSquareSum(int c) {
        int sq = sqrt(c);
        int si = 0;
        int ei = sq;
        while(si <= ei){
            if((double)si*si + (double)ei*ei == c){
                return true;
            }else if((double)si*si + (double)ei*ei >c){
                ei--;
            }else {
                si++;
            }
        }
        return false;
        
    }
};