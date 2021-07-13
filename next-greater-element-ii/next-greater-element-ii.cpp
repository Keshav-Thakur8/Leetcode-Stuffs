class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0 ; i<2*n ; i++){
            //if we reached end then again start from first(i.e circular way)
            int idx = i >= n ? i - n : i;
            while(!st.empty() && nums[st.top()]<nums[idx]){
                ans[st.top()] = nums[idx];
                st.pop();
            }
            st.push(idx);
        }
        return ans;
    }
};