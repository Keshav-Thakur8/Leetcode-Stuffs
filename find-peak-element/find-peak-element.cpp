class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int si = 0;
        int ei = n-1;
        while(si <= ei){
            int mid = (si+ei)/2;
            if((mid-1<0 || nums[mid]>nums[mid-1]) && (mid+1>=n || nums[mid]>nums[mid+1])){
                return mid;
            }
            else if(mid-1<0 || nums[mid]>nums[mid-1]){
                si = mid+1;
            }
            else{
                ei = mid-1;
            }
        }
        return -1;
    }
};