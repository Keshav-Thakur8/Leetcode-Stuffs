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
    long long tot_sum = 0, ans = 0;
    int solve(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int sum = root->val + solve(root->left) + solve(root->right);
        ans = max(ans, (tot_sum - sum)*sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        tot_sum = solve(root);
        solve(root);
        return ans % int(1e9+7);
    }
};