class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();
        int conti_one = 0;
        int conti_zero = 0;
        int max_zero_len = 0;
        int max_one_len = 0;
        for(int i=0 ; i<n ; i++) {
            if(s[i] == '0') {
                conti_zero++;
                if(s[i] != s[i+1]) {
                    max_zero_len = max(max_zero_len, conti_zero);
                    conti_zero = 0;
                }
            }
            
            if(s[i] == '1') {
                conti_one++;
                if(s[i] != s[i+1]) {
                    max_one_len = max(max_one_len, conti_one);
                    conti_one = 0;
                }
            }
        }
        if(max_one_len > max_zero_len) {
            return true;
        }
        else{
            return false;
        }
    }
};