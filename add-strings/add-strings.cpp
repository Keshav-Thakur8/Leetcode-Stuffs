class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int carry = 0;
        string ans = "";
        int i=n1-1, j=n2-1;
        while(i >= 0 || j >= 0 || carry){
            long sum = 0;
            if(i>=0){
                sum = sum+(num1[i]-'0');
                i--;
            }
            if(j>=0){
                sum = sum+(num2[j]-'0');
                j--;
            }
            sum = sum+carry;
            carry = sum/10;
            sum = sum%10;
            ans = to_string(sum)+ans;
        }
        //verse(ans.begin(), ans.end());
        return ans;
        
    }
};