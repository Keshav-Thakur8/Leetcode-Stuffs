class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //Simple approach
        // int k = 0;
        // int j = m;
        // while(j<=m+n && k<n){
        //     nums1[j] = nums2[k];
        //     j++;
        //     k++;
        // }
        // sort(nums1.begin(),nums1.end());
        //start traversing array from the end
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            } else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        //this loop is for the case in which nums2 is longer than nums1
        //simply copy rest of the element to nums1
        while(j>=0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        
        
    }
};
