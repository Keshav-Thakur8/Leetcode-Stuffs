class Solution {
public:
    double revNum(int x){
        double rev = 0;
        while(x!=0){
            rev = rev * 10 + x % 10;
            x = x / 10;
        }
        return rev;
    }
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        if(revNum(x) == x){
            return true;
        }
        else{
            return false;
        }
    }
};