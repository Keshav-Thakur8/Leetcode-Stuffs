class Solution {
public:
    bool isPowerOfTwo(int n) {
        //just check if the AND of n and n-1  is equal to zero
        //if zero then n is the power of two else n is not the power of two
        if(n>0 && (n&(n-1))==0)
            return true;
        return false;
        
    }
};