// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int si = 1;
        int ei = n;
        int ans = n;
        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(isBadVersion(mid)) {
                ans = mid;
                ei = mid-1;
            }
            else{
                si = mid+1;
            }
        }
        return ans;
    }
};