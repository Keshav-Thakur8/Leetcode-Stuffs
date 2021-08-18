class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) {
            return "Zero";
        }
        string ans = "";
        string Thousands[4] = {"","Thousand","Million","Billion"};
        string Ones[10]= {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string Tens[10]= {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string Tens1[10]= {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        int i = 0;
        while(num != 0) {
            int ones = 0, tens = 0, hundred = 0;
            string s = "";
            
            ones = num%10;
            num = num/10;
            tens = num%10;
            num = num/10;
            
            if(tens == 1) {
                s = Tens1[ones] + " " + s;
            }
            else{
                if(ones > 0)
                    s = Ones[ones] + " " + s;
                if(tens > 0)
                    s = Tens[tens] + " " + s;
            }
            
            hundred = num%10;
            num = num/10;
            if(hundred > 0) {
                s = Ones[hundred] + " Hundred" + " " + s;
            }
            
            if(i>0 && s.size()>0) 
	            ans = s + Thousands[i] + " " + ans;
            else
	            ans = s + ans;
            i++;
        }

        return ans.substr(0,ans.size()-1); 
    }
};