class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<int> help(num1.size() + num2.size(), 0);
        for(int i = num1.size()-1 ; i>=0 ; i--) {
            for(int j = num2.size()-1 ; j>=0 ; j--) {
                help[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
                help[i+j] += help[i+j+1]/10;
                help[i+j+1] %= 10;
            }
        }
        //remove leading zeros if any
        int i=0;
        while(i < help.size() && help[i] == 0) {
            i++;
        }
        
        //compute final answer
        string ans = "";
        while(i < help.size()) {
            ans.push_back(help[i] + '0');
            i++;
        }
        
        return ans;
        
    }
};