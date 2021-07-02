class Solution {
public:
    bool isPerfectSquare(int num) {
        int si = 0;
        int ei = num;
        //double ans = 0;
        while(si <= ei){
            int mid = (si+ei)/2;
            if((double)mid*mid == num){
                return true;
            }
            else if((double)mid*mid < num){
                si = mid+1;
            }
            else{
                ei = mid-1;
            }
        }
        return false;
        
    }
};