class Solution {
public:
        int digitSquareSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
        // bool isHappy(int n) {
        //     int slow = n;
        //     int fast = digitSquareSum(n);
        //     while(slow != fast){
        //         slow = digitSquareSum(slow);
        //         fast = digitSquareSum(digitSquareSum(fast));
        //     }
        //     if(slow == 1)
        //         return true;
        //     else
        //         return false;
    bool isHappy(int n) {
            int slow = n;
            int fast = n;
            do{
                slow = digitSquareSum(slow);
                fast = digitSquareSum(digitSquareSum(fast));
            }while(slow != fast);
            if(slow == 1)
                return true;
            else
                return false;
        }
};
