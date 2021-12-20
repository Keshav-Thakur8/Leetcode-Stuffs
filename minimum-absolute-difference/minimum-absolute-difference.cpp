class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        int minDiff = abs(arr[1]-arr[0]);
        for(int i=1 ; i<n-1 ; i++){
            minDiff = min(abs(arr[i]-arr[i+1]), minDiff);
        }
        for(int i=0 ; i<n-1 ; i++){
            if(abs(arr[i+1]-arr[i]) == minDiff){
                ans.push_back(vector<int>{arr[i], arr[i+1]});
            }
            
        }
        return ans;
        
    }
};