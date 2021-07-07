class Solution {
public:
    //int ans = 0;
    int addDigits(int num) {
        // int sum = 1+(num-1)%9;
        // return sum;
        // int rem = num%10;
        // num = num/10;
        // ans = rem+num;
        // if(ans >= 10){
        //     addDigits(ans);
        // }
        // return ans;
        
        
        //recursive approach
        int ans = 0;
        while(num != 0){
            ans += num%10;
            num /= 10;
            
        }
        if(ans/10 == 0)
            return ans;
        else
            return addDigits(ans);
    }
};