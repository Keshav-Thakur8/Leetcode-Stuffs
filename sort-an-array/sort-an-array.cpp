class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end){
        int i,j,k;
        vector<int> temp(end-start+1);
        i = start;
        k = 0;
        j = mid+1;
        while (i <= mid && j <= end)
        {
            if (nums[i] <= nums[j])
            {
                temp[k] = nums[i];
                k++;
                i++;
            }
            else
            {
                temp[k] = nums[j];
                k++;
                j++;
            }
        }
        while (i <= mid)
        {
            temp[k] = nums[i];
            k++;
            i++;
        }
        while (j <= end)
        {
            temp[k] = nums[j];
            k++;
            j++;
        }
        //copy temp to original array nums
        for(i = start; i <= end; i++) 
           nums[i] = temp[i-start];
    }
    void merge_sort(vector<int>& nums,int start, int end) {
        //if array is already sorted
        if(end-start+1 <= 1){
            return;
        }
        int mid = start+(end-start)/2;
        merge_sort(nums,start,mid);
        merge_sort(nums,mid+1,end);
        
        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        merge_sort(nums, 0, n-1);
        return nums;
        
    }
};