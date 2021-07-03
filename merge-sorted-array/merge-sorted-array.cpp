class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = 0;
        int j = m;
        while(j<=m+n && k<n){
            nums1[j] = nums2[k];
            j++;
            k++;
        }
        sort(nums1.begin(),nums1.end());
        
        
    }
};