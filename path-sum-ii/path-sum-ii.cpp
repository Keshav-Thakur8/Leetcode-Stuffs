/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    void solve(TreeNode* root, int targetSum, vector<int> contribution) {
        //base case
        if(root == NULL) {
            //ans.push_back(contribution);
            return;
        }
        if(root->val == targetSum && root->left == NULL && root->right == NULL) {
            contribution.push_back(root->val);
            ans.push_back(contribution);
            return;
        }
        
        //recursive step
        contribution.push_back(root->val);
        if(root->left != NULL) {
            solve(root->left, targetSum-root->val, contribution);
        }
        if(root->right != NULL) {
            solve(root->right, targetSum-root->val, contribution);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum, {});
        return ans;
    }
};