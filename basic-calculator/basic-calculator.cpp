class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        stack<int> exprssn;
        int result = 0;
		//considering a number to be positive by default
        int sign = 1;
        for(int i = 0;i<len;i++)
        {       
			//processing the number from string
           if('0'<= s[i] && s[i]<= '9')
           {
               int val = 0;
               while(i<len && ('0'<= s[i] && s[i]<= '9'))
               {
                   val = val*10 + (s[i]-'0');
                   i++;
               }
               i--;
			   //set the sign
               val= val*sign;  
               result+=val;
               sign = 1;
           }
		   //set the value to be negative following the minus sign
           else if(s[i] == '-')
		   {
               sign*=-1;
		   }
		   //push calculated currently calculated value with sign into stack
           else if(s[i] == '(')
           {
               exprssn.push(result);
               exprssn.push(sign);
               sign = 1;
               result = 0;
           }
		   //get the last result and the sign from the stack
           else if(s[i] == ')')
           {
               result*= exprssn.top();
               exprssn.pop();
               result += exprssn.top();
               exprssn.pop();
           }
       }
       return result;
    }
};