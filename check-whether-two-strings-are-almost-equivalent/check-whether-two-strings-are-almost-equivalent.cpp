class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int n = word1.size();
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(int i=0 ; i<n ; i++) {
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        for(char c='a' ; c<='z' ; c++) {
            if(abs(mp1[c]-mp2[c]) > 3) {
                return false;
            }
        }
        return true;
    }
};