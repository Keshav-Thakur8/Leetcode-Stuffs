class Solution {
public:
    int mySqrt(int x) {
        int si = 0;
        int ei = x;
        double ans = 0;
        while(si <= ei){
            int mid = (si+ei)/2;
            if((double)mid*mid == x){
                return mid;
            }
            else if((double)mid*mid < x){
                ans = mid;
                si = mid+1;
            }
            else {
                ei = mid-1;
            }
        }
        return ans;
        
    }
};