class Solution {
public:
    // bool isPresent(string str, vector<string>& words1, vector<string>& words2) {
    //     for(int i=0 ; i<words1.size()|| i<words2.size() ; i++) {
    //         if(words1[i] == str || words2[i] == str) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ans = 0;
        int n1 = words1.size();
        int n2 = words2.size();
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        for(int i=0 ; i<n1 ; i++) {
            mp1[words1[i]]++;
        }
        for(int i=0 ; i<n2 ; i++) {
            mp2[words2[i]]++;
        }
        
        for(auto it : mp1) {
            if(it.second == 1) {
                if(mp2[it.first] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};