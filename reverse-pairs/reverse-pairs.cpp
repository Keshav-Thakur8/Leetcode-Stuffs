class Solution {
public:
    int merge(vector<int>& nums, int start,int mid,int end){
        int cnt = 0;
        int j = mid+1; //starting point of right half array
        //main part
        //for every left element we will check right element
        for(int i=start ; i<=mid ; i++){
            while(j<=end && nums[i]>(long)2*nums[j]){
                j++;
            }
            cnt += j-(mid+1);
        }
        //merge process from here
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
        //if left or right get exhausted
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
        //Base Case:Single element in the vector
        if(start>=end){
            return 0;
        }
        int mid = (start+end)/2;
        //Left part Recursion
        int inv = merge_sort(nums,start,mid);
        //Right part Recursion
        inv += merge_sort(nums,mid+1,end);
        inv += merge(nums,start,mid,end);
        return inv;
        
    }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums,0,nums.size()-1);
    }
};
