class Solution {
public:
    int atMostKDistinct(vector<int>& A,int n,int k){
        int count = 0;
        int left = 0;
        int right = 0;

        unordered_map<int,int> mp;

        while(right < n){
            //add current element in the map
            if(mp.find(A[right]) == mp.end()){
                mp[A[right]] = 1;
            }
            else{
                mp[A[right]]++;
            }
            
            //start contracting window
            while(mp.size() > k){
                mp[A[left]]--;
                if(mp[A[left]] == 0){
                    mp.erase(A[left]);
                }
                left++;
            }

            count += right-left+1;
            right++;
            }


        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return atMostKDistinct(nums,n,k) - atMostKDistinct(nums,n,k-1);
    }
};