class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> s_hash(26,0);
        vector<int> p_hash(26,0);
        int s_len = s.size();
        int p_len = p.size();
        
        //corner case
        if(p_len > s_len) {
            return ans;
        }
        
        //put starting window in hash
        int left = 0;
        int right = 0;
        while(right < p_len) {
            s_hash[s[right]-'a'] += 1;
            p_hash[p[right]-'a'] += 1;
            right++;
        }
        
        //ek extra bhag jata hai
        right -= 1;
        
        while(right < s_len) {
            if(p_hash == s_hash)
                ans.push_back(left);
            right += 1;
            if(right != s_len)
                s_hash[s[right]-'a'] += 1;
            s_hash[s[left]-'a'] -= 1;
            left += 1;
        }
        return ans;
    }
};