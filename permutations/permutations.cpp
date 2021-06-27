class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& A, vector<bool>&B, vector<int> contribution){
        //Base Case
        if(contribution.size() == A.size()){
            res.push_back(contribution);
        }
        
        //Recursive Step
        for(int i=0 ; i<A.size() ; i++){
            if(B[i] == false){
                continue;
            }
            contribution.push_back(A[i]);
            B[i] = false;
            helper(A, B, contribution);
            //undo step
            contribution.pop_back();
            B[i] = true;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> b(n, 1);
        vector<int> contribution;
        helper(nums, b, contribution);
        return res;
    }
};