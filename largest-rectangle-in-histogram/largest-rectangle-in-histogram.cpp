class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        //Next smaller elements
        vector<int> next_small(n,-1);
        stack<int> s;
        for(int i=0 ; i<n ; i++){
            while(!s.empty() && heights[s.top()] > heights[i]){
                next_small[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            next_small[s.top()] = n;
            s.pop();
        }
        
        //Previous Smaller Elements
        //we can use same stack since here the stack will be empty
        vector<int> prev_small(n,-1);
        for(int i=n-1 ; i>=0 ; i--){
            while(!s.empty() && heights[s.top()] > heights[i]){
                prev_small[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            prev_small[s.top()] = -1;
            s.pop();
        }
        
        //For every i find the array
        int max_height = INT_MIN;
        for(int i=0 ; i<n ; i++){
            //suppose 2nd index is the prex small
            //ans 5th index is the next small
            //actual rectangle lies from the 3rd index to the 4th index
            //so width is 2
            int width = next_small[i]-prev_small[i]-1;
            int area = width*heights[i];
            max_height = max(max_height,area);
        }
        return max_height;
        
    }
};