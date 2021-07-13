class Solution {
public:
    double myPow(double x, int n) {
        // //base case
        // if(n==0){
        //     return 1;
        // }
        // double ans = pow(x,n/2);
        // if(n%2){
        //     return n<0 ? 1/x*ans*ans : x*ans*ans;
        // }else{
        //     return ans*ans;
        // }
        double ans = 1.0;
        long long a = n;
        if(a<0){
            a = -1*a;
        }
        while(a != 0){
            if(a%2==1){
                ans = ans*x;
                a = a-1;
            }
            else{
                x = x*x;
                a = a/2;
            }
        }
        if(n<0){
            ans = (double)(1.0)/(double)(ans);
        }
        return ans;
        
    }
};