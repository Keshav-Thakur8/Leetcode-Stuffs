class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size()-1;
        int len2 = b.size()-1;
        string res = "";
        int temp = 0;
        while(len1>=0 || len2>=0 || temp == 1){
            temp += ((len1 >= 0)? a[len1] - '0': 0);
            temp += ((len2 >= 0)? b[len2] - '0': 0);
            res = char(temp % 2 + '0') + res;
            temp /= 2;
            len1--; len2--;
        }
        return res;
        
    }
};