class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int i=0,j,curr=s[0];
        int ans = INT_MIN;
        while(i<n) {
            j = i+1;
            while(j<n && curr==s[j]){
                j++;
            }
            ans = max(ans, j-i);
            curr = s[j];
            i = j;
        }
        return ans;
    }
};