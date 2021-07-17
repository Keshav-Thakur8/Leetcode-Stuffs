class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        //prefix xor of the given vector
        for(int i=1 ; i<arr.size() ; i++){
            arr[i] = arr[i-1]^arr[i];
        }
        //main step
        for(int j=0 ; j<queries.size() ; j++) {
            int left = queries[j][0];
            int right = queries[j][1];
            
            //if left is  0 the simply return xor at right pos in arr vector
            if(left == 0){
                ans.push_back(arr[right]);
            }
            //tricky step
            else {
                ans.push_back(arr[left-1] ^ arr[right]);
            }
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        //Brute Force : TLE
        // int xr = 0;
        // vector<int> ans;
        // for(int i=0 ; i<queries.size() ; i++){
        //     vector<int> temp = queries[i];
        //     int left = temp[0];
        //     int right = temp[1];
        //     for(int j=left ; j<=right ; j++){
        //         xr ^= arr[j];
        //     }
        //     ans.push_back(xr);
        //     xr = 0;
        // }
        // return ans;
    }
};