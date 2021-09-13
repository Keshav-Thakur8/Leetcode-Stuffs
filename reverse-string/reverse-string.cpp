class Solution {
public:
    // void reverse(vector<char>& s, int si, int ei) {
    //     if(si >= ei) {
    //         return;
    //     }
    //     swap(s[si], s[ei]);
    //     si++;
    //     ei--;
    //     reverse(s, si, ei);
    // }
    void reverseString(vector<char>& s) {
        // reverse(s, 0, s.size()-1);
        //naive approach
        int n = s.size();
        int si = 0;
        int ei = n-1;
        while(si < ei) {
            swap(s[si], s[ei]);
            si++;
            ei--;
        }
    }
};