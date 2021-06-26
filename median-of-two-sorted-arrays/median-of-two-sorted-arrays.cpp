class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int len1 = nums1.size();
        int len2 = nums2.size();
        for(int i=0; i<len1; i++){
            ans.push_back(nums1[i]);
        }
        for(int i=0; i<len2; i++){
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(), ans.end());
        double median = 0;
        int n = ans.size();
        if(n%2 == 0){
            median = (0.0+ ans[n/2] + ans[n/2 -1])/2;
        }
        else{
            median = ans[n/2];   
        }
        return median;
    }
};