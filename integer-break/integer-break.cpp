class Solution {
public:
    int integerBreak(int n) {
        if(n == 2 || n == 3) {
            return n-1;
        }
        int res = 1;
        while(n%3 != 0 && n >= 2) {
            n -= 2;
            res *= 2;
        }
        int k = n/3;
        res *= pow(3,k);
        
        return res;
        
    }
};