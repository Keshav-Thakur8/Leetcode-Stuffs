class Solution {
public:
    void helper(int left_idx, int right_idx, vector<char>& s) {
        if(left_idx >= right_idx) {
            return;
        }
        swap(s[left_idx], s[right_idx]);
        helper(left_idx+1, right_idx-1, s);
    }
    void reverseString(vector<char>& s) {
        int n = s.size();
        helper(0, n-1, s);
    }
};