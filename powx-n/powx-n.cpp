class Solution {
public:
    double myPow(double x, int n) {
        //base case
        if(n==0){
            return 1;
        }
        double ans = pow(x,n/2);
        if(n%2){
            return n<0 ? 1/x*ans*ans : x*ans*ans;
        }else{
            return ans*ans;
        }
        
    }
};