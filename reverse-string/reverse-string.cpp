class Solution {
public:
    void reverse(vector<char>& s, int si, int ei) {
        if(si >= ei) {
            return;
        }
        swap(s[si], s[ei]);
        si++;
        ei--;
        reverse(s, si, ei);
    }
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size()-1);
        // //naive approach
        // int n = s.size();
        // int i = 0;
        // int j = n-1;
        // while(i<=j) {
        //     swap(s[i],s[j]);
        //     i++;
        //     j--;
        // }
    }
};