class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //hashmap approach
        unordered_map<char,int> mp;
        int n = s.size();
        if(n == 0) {
             return 0;
        }
        int left = 0;
        int right = 0;
        int len = INT_MIN;
        while(right < n) {
            if(mp.find(s[right]) != mp.end()) {
                left = max(mp[s[right]]+1, left);
            }
            mp[s[right]] = right;
            
            len = max(len,right-left+1);
            right++;
        }
        return len;
        
        // //sliding window approach
        // //TC: O(2n)
        // int n = s.size();
        // if(n == 0) {
        //     return 0;
        // }
        // set<char> st;
        // int left = 0;
        // int right = 0;
        // int max_length = INT_MIN;
        // while(right < n) {
        //     if(st.count(s[right]) == 0) {
        //         st.insert(s[right]);
        //         max_length = max(max_length, right-left+1);
        //         right++;
        //     }
        //     else {
        //         st.erase(s[left]);
        //         left++;
        //     }
        // }
        // return max_length;
    }
};
