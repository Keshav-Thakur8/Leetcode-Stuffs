class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        for(int i=0 ; i<t.size() ; i++){
            m[t[i]]++;
        }
        for(int i=0 ; i<s.size() ; i++){
            m[s[i]]--;
        }
        for(auto i = m.begin(); i != m.end(); i++){
            if(i->second > 0)
                return i->first;
        }
        return '-1';
        
    }
};