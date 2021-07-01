class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n =  citations.size();
        int i = 0;
        int j = n-1;
        int mid, ans=0;
        while(i <= j)
        {
            mid = i + (j-i) / 2;
            if(citations[mid] >= (n - mid)){
                ans = n-mid;
                j = mid - 1;
            }
            else
                i = mid + 1;
        }
        return ans;
    }
};
