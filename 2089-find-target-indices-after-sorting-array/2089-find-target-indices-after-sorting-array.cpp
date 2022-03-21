class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int idx = nums.size();
        int si = 0;
        int ei = nums.size()-1;
        int mid;
        while(si <= ei) {
            mid = si + (ei-si)/2;
            if(nums[mid] == target) {
                idx = mid;
                ei = mid-1;
            }
            else if(nums[mid] > target) {
                ei = mid-1;
            }
            else {
                si = mid+1;
            }
        }
        return idx;
    }
    
    //for last occurence
    int upperBound(vector<int>& nums, int target) {
        int idx = -1;
        int si = 0;
        int ei = nums.size()-1;
        int mid;
        while(si <= ei) {
            mid = si + (ei-si)/2;
            if(nums[mid] == target) {
                idx = mid;
                si = mid+1;
            }
            else if(nums[mid] > target) {
                ei = mid-1;
            }
            else {
                si = mid+1;
            }
        }
        return idx;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int up = upperBound(nums, target);
        int down = lowerBound(nums, target);
        vector<int> ans;
        for(int i=down ; i<=up ; i++) {
            ans.push_back(i);
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // for(int i=0 ; i<nums.size() ; i++) {
        //     if(nums[i] == target) {
        //         ans.push_back(i);
        //     }
        // }
        // return ans;
        // int si = 0;
        // int ei = nums.size()-1;
        // while(si <= ei) {
        //     int mid = si + (ei-si)/2;
        //     if(nums[mid] == target) {
        //         ans.push_back(mid);
        //         ei = mid-1;
        //     }
        //     else if(nums[mid] > target) {
        //         ei = mid-1;
        //     }
        //     else {
        //         si = mid+1;
        //     }
        // }
        // sort(ans.begin(), ans.end());
        // return ans;
    }
};