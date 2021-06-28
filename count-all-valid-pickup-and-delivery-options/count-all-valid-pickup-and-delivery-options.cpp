#define MOD 1000000007
class Solution {
public:
     int countOrders(int n) {
//         if(n == 1) {
//             return 1;
//         }
//         return ((2*n-1) * n * countOrders(n-1))%pow(10,9)+7;
        
        long prev = 1;
        for(long i=2 ; i<=n ; i++){
            long curr = (prev%MOD * i * (2*i - 1))%MOD;
            prev = curr;
        }
        return (int)prev;
        
    }
};