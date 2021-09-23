class Solution {
public:
    vector<vector<int>> res;
    void helper(int si, int n, int k, vector<int> contribution){
        //Base Case
        if(k==0){
            res.push_back(contribution);
            return;
        }
            
        if(si > n)
            return;
        //pruning:removing unwanted part
        //i.e if k is greater then the size of vector
        if(k>(n-si+1))
            return;
        
        //Recursive Step
        //c1
        helper(si+1, n, k, contribution);
        
        //c2: include first index
        contribution.push_back(si);
        helper(si+1, n, k-1, contribution);
    }
    vector<vector<int>> combine(int n, int k) {
        helper(1, n, k, {});
        return res;
    }
};