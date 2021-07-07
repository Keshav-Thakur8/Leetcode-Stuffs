class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        int curr_max = arr[0];
        for(int i=1 ; i<arr.size() ; i++){
            curr_max = max(curr_max,arr[i]);
            m[curr_max]++;
            if(m[curr_max]>=k){
                return curr_max;
            }
        }
        return curr_max;
    }
};