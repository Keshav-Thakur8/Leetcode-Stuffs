class Solution {
public:
    void afterDecimal(long num, long den, string& decimal) {
        //map to store the repeating numerator
        unordered_map<long,long> m;
        long q;
        long r;
        while(num != 0){
            q = num/den;
            r = num%den;
            //if not find in the map then insert it in map
            if(m.find(num) == m.end()){
                m[num] = decimal.size();
                decimal += to_string(q);
                num = r*10;
                
            }
            //otherwise append the brackets
            else{
                decimal = decimal.substr(0, m[num]) + "(" + decimal.substr(m[num], decimal.size()-m[num]) + ")";
                break;
            }
            
        }
    }
    string fractionToDecimal(int numerator, int denominator) {
        //edge case
        if(numerator == 0){
            return "0";
        }
        //this string will store answer
        string ans = "";
        //if any of the numerator or denominator in negative
        if((numerator<0 && denominator>0) || (numerator>0 && denominator<0)) {
            ans += "-";
        }
        long num = (long)abs(numerator);
        long den = (long)abs(denominator);
        
        //calculate quotient
        long q = num/den;
        //calculate remainder
        long r = num%den;
        
        //append quotient to the string
        ans += to_string(q);
        //if remainder is zero, means string ans is our answer
        if(r == 0){
            return ans;
        }
        //otherwise append . after qoutient
        ans += ".";
        
        //make a function call to perform further steps
        afterDecimal(r*10, den, ans);
        return ans;
    }
};