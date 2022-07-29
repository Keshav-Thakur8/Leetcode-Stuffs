class Solution {
public:
    void helper(int left_idx, vector<char>& s, int n) {
        if(left_idx >= n/2) {
            return;
        }
        swap(s[left_idx], s[n-left_idx-1]);
        helper(left_idx+1, s, n);
    }
    // void helper(int left_idx, int right_idx, vector<char>& s) {
    //     if(left_idx >= right_idx) {
    //         return;
    //     }
    //     swap(s[left_idx], s[right_idx]);
    //     helper(left_idx+1, right_idx-1, s);
    // }
    void reverseString(vector<char>& s) {
        int n = s.size();
        //helper(0, n-1, s);
        helper(0, s, n);
    }
};