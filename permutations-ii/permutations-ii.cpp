class Solution {
public:
//     vector<vector<int>> res;
//     void helper(vector<int>& A, vector<bool>&B, vector<int> contribution){
//         //Base Case
//         if(contribution.size() == A.size()){
//             res.push_back(contribution);
//         }
        
//         //Recursive Step
//         for(int i=0 ; i<A.size() ; i++){
//             if(B[i] == false){
//                 continue;
//             }
//             contribution.push_back(A[i]);
//             B[i] = false;
//             helper(A, B, contribution);
//             //undo step
//             contribution.pop_back();
//             B[i] = true;
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> b(n, 1);
//         vector<int> contribution;
//         helper(nums, b, contribution);
//         sort(res.begin(), res.end());
//         res.erase(unique(res.begin(), res.end()), res.end());
//         return res;
//     }
    
    //Effective Solution
    void helper(vector<int> v,vector<vector<int>> &ans,int idx){
        if(idx == v.size()){
            ans.push_back(v);
            return;
        }
        for (int i = idx; i < v.size(); i++){
            if(i != idx && v[i]==v[idx]){
                continue;
            }
            swap(v[i],v[idx]);
            helper(v,ans ,idx+1);
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        helper(nums,ans,0);
        return ans;
    }
};
