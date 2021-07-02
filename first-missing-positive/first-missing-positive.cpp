class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Separate non-positive from positive.
        int n = nums.size(), i, j;

        // j is the first avaiable position from the end
        // where you can insert a non-positive integer.
        i = 0, j = n - 1;
        while (i <= j) {
            //Do nothing
            if(nums[i]>0){
                i++;
                continue;
            }
            swap(nums[i], nums[j]);
            j--;

        }

        // Size of working set.
        int new_size = j + 1;

        // Mark the elements in between [1, new_size] that are size.
        for (i = 0; i < new_size; i++) {
            if (abs(nums[i]) > new_size)
            continue;

            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;

        }

        // Find the first missing positive.
        for (i = 0; i < new_size; i++) {
            if (nums[i] > 0)
                return i + 1;

        }

        return new_size + 1;
    }
};