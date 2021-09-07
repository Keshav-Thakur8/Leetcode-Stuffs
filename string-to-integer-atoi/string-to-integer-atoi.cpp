class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()){
            return 0;
        }
        int index = 0;
        while(s[index] == ' '){
            index++;
        }
        int sign = 1;
        if(index < s.size()){
            if(s[index] == '-'){
                sign = -1;
                index++;
            }
            else if(s[index] == '+'){
                index++;
            }
        }
        long long sum = 0;
        while(isdigit(s[index])){
            sum = sum*10 + s[index] - '0';
            if(sum > (long long)INT_MAX && sign == 1){
                return INT_MAX;
            }
            if(sum > (long long)INT_MAX+1 && sign == -1){
                return INT_MIN;
            }
            index++;
        }
        return (int)(sum*sign);
        
    }
};