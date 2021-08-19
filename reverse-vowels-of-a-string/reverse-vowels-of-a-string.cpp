class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        string ans = s;
        int n = s.size();
        int si = 0;
        int ei = n-1;
        while(si <= ei) {
            if(isVowel(ans[si]) && isVowel(ans[ei])) {
                swap(ans[si], ans[ei]);
                si++;
                ei--;
            }
            else if(isVowel(ans[si]) && !isVowel(ans[ei])) {
                ei--;
            }
            else if(!isVowel(ans[si]) && isVowel(ans[ei])) {
                si++;
            }
            else {
                si++;
                ei--;
            }
        }
        return ans;
    }
};