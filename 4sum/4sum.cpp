class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<vector<int>> s;
        if(n<=3){
            return ans;
        }
        for(int i=0 ; i<n-1 ; i++){
            int a = nums[i];
            for(int j = i+1 ; j<n ; j++){
                int b = nums[j];
                int c = target-(a+b);
                int si = j+1;
                int ei = n-1;
                while(si<ei){
                    int x = nums[si];
                    int y = nums[ei];
                    if(x+y<c){
                        si++;
                    }
                    else if(x+y>c){
                        ei--;
                    }
                    else{
                        s.push_back({a,b,x,y});
                        si++;
                        ei--;
                    }
                    
                }
            }
        }
        for(int i=0 ; i<s.size() ; i++){
            ans.push_back(s[i]);
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end() );
        return ans;
        
    }
};