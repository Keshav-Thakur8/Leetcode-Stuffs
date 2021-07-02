class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int minVal = *min_element(nums.begin(),nums.end());

        int maxVal = *max_element(nums.begin(),nums.end());

        int n = nums.size();

        vector<vector<int>> bucket(n+1);

        if(minVal==maxVal) return 0;

        int range = (maxVal-minVal)/n +1;

        for(int i=0;i<n;i++){

            int index = (nums[i]-minVal)/range;

            bucket[index].push_back(nums[i]);

        }

        int maxSum = INT_MIN;

        int prev_val = minVal;

        for(auto b:bucket){

            sort(b.begin(),b.end());

            for(int i:b){

                maxSum = max(maxSum,i-prev_val);

                prev_val = i;

            }

        }

        return maxSum;
    }
};