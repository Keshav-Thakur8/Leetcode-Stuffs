class Solution {
public:
    int solve(string &a, char ch, int &k) {
        int n = a.size();
        int left = 0;
        int ans = 0;
        int cnt = 0;
        for(int right=0 ; right<n ; right++) {
            if(a[right] == ch) {
                cnt++;
            }
            while(cnt > k) {
                if(a[left] == ch) {
                    cnt--;
                }
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey, 'T', k), solve(answerKey, 'F', k));
    }
};