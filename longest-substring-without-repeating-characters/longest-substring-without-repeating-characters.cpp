class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) {
            return 0;
        }
        set<char> st;
        int left = 0;
        int right = 0;
        int max_length = INT_MIN;
        while(right < n) {
            if(st.count(s[right]) == 0) {
                st.insert(s[right]);
                max_length = max(max_length, right-left+1);
                right++;
            }
            else {
                st.erase(s[left]);
                left++;
            }
        }
        return max_length;
    }
};