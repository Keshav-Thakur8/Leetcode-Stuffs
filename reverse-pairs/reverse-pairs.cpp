class Solution {
public:
    int merge(vector<int>& nums, int start,int mid,int end){
        int cnt = 0;
        int j = mid+1;
        for(int i=start ; i<=mid ; i++){
            while(j<=end && nums[i]>(long)2*nums[j]){
                j++;
            }
            cnt += j-(mid+1);
        }
        vector<int> helper;
        int left = start;
        int right = mid+1;
        while(left<=mid && right<=end){
            if(nums[left] <= nums[right]){
                helper.push_back(nums[left]);
                left++;
            } else {
                helper.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            helper.push_back(nums[left]);
            left++;
        }
        while(right<=end){
            helper.push_back(nums[right]);
            right++;
        }
        //now copy helper to nums
        for(int i=start ; i<=end ; i++){
            nums[i] = helper[i-start];
        }
        return cnt;
    }
    int merge_sort(vector<int>& nums,int start,int end){
        if(start>=end){
            return 0;
        }
        int mid = (start+end)/2;
        int inv = merge_sort(nums,start,mid);
        inv += merge_sort(nums,mid+1,end);
        inv += merge(nums,start,mid,end);
        return inv;
        
    }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums,0,nums.size()-1);
    }
};