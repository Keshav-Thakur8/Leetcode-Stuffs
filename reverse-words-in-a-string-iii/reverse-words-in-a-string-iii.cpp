class Solution {
public:
    void reverse(string &ans, int si, int ei) {
        while(si <= ei) {
            swap(ans[si], ans[ei]);
            si++;
            ei--;
        }
    }
    string reverseWords(string s) {
        string ans = s;
        int si = 0;
        int n = s.size();
        for(int i=0 ; i<=n ; i++) {
            if(i==n || ans[i]==' ') {
                reverse(ans, si, i-1);
                //reverse(&ans[si], &ans[i]);
                si = i+1;
            }
        }
        return ans;
    }
};