/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int si = 0;
        int ei = n-1;
        int mid;
        while(si < ei){
            mid = (si+ei)/2;
            int left = mountainArr.get(mid-1);
            int right = mountainArr.get(mid+1);
            int m = mountainArr.get(mid);
            if(m>left && m>right){
                break;
            }
            else if(m>left){
                si = mid+1;
            }
            else{
                ei = mid;
            }
        }
        
        if(mountainArr.get(mid) == target) return mid;
        si = 0;
        ei = mid-1;
        
        while(si <= ei){
            mid = si + (ei - si)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) > target) ei = mid-1;
            else si = mid+1;
        }
        
        si = mid;
        ei = n-1;
        
        while(si <= ei){
            mid = si + (ei - si)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) < target) ei = mid-1;
            else si = mid+1;
        }
        
        return -1;
    }
};
