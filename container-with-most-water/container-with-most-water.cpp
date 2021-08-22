class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int min_height;
        int i = 0;
        int j = height.size()-1;
        while(i < j) {
            min_height = min(height[i], height[j]);
            ans = max(ans, min_height*(j-i));
            if(height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};