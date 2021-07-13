class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> ans(n,-1);
        for(int i=0 ; i<n ; i++){
            // Finding out all days for which A[i] is the answer.
            // Finding out days < i s.t. A[j] < A[i] and i is the first such index.
            // Stack all the unprocessed days.
            // Indices in the stack.
            while(!s.empty() && temperatures[i]>temperatures[s.top()]){
                ans[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        //for all elements where next greater doesn't exist
        while(!s.empty()){
            ans[s.top()] = 0;
            s.pop();
        }
        return ans;
    }
};
