class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int countVowelSubstrings(string word) {
        int res = 0;
        int n = word.size();
        set<char> s;
        for(int i=0 ; i<n ; i++) {
            for(int j=i ; j<n ; j++) {
                if(!isVowel(word[j])) {
                    break;
                }
                s.insert(word[j]);
                
                if(s.size() == 5) {
                    res++;
                }
            }
            s.clear();
        }
        return res;
        
    }
};