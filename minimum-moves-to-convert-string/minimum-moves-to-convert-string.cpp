class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        int i = 0;
        int cnt = 0;
        while(i<n) {
            if(s[i] == 'O') {
                i++;
            }
            else {
                cnt++;
                i = i+3;
            }
        }
        return cnt;
    }
};