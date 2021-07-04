class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);
        for(int i=0 ; i<s.size() ; i++){
            freq[s[i]-'a']++;
        }
        for(int j=0 ; j<t.size() ; j++){
            freq[t[j]-'a']--;
        }
        for(int k=0 ; k<freq.size() ; k++){
            if(freq[k] != 0)
                return false;
        }
        return true;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s == t){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        
    }
};
