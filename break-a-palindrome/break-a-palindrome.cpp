class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n <= 1) {
            return "";
        }
        for(int i=0 ; i<n/2 ; i++) {
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        //if string only has 'a'
        palindrome[n-1] = 'b';
        return palindrome;
    }
};