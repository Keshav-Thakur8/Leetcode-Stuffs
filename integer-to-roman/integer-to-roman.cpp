class Solution {
public:
    string intToRoman(int num) {
        string ans;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        for(int i=0 ; num!=0 ; i++){
            while(num >= val[i]){
                num -= val[i];
                ans += sym[i];
            }
        }
        // if(num/1000){
        //     int k = num/1000;
        //     for(int i=0 ; i<k ; i++){
        //         ans += "M";
        //     }
        //     num %= 1000;
        // }
        // if(num/900){
        //     ans += "CM";
        //     num %= 900;
        // }
        // if(num/500){
        //     ans += "D";
        //     num %= 500;
        // }
        // if(num/400){
        //     ans += "CD";
        //     num %= 400;
        // }
        // if(num/100){
        //     int k = num/100;
        //     for(int i=0 ; i<k ; i++){
        //         ans += "C";
        //     }
        //     num %= 100;
        // }
        // if(num/90){
        //     ans += "XC";
        //     num %= 90;
        // }
        // if(num/50){
        //     ans += "L";
        //     num %= 50;
        // }
        // if(num/40){
        //     ans += "XL";
        //     num %= 40;
        // }
        // if(num/10){
        //     int k = num/10;
        //     for(int i=0 ; i<k ; i++){
        //         ans += "X";
        //     }
        //     num %= 10;
        // }
        // if(num/9){
        //     ans += "IX";
        //     num %= 9;
        // }
        // if(num/5){
        //     ans += "V";
        //     num %= 5;
        // }
        // if(num/4){
        //     ans += "IV";
        //     num %= 4;
        // }
        // if(num/1){
        //     int k = num;
        //     for(int i=0 ; i<k ; i++){
        //         ans += "I";
        //     }
        // }
        return ans;
    }
};