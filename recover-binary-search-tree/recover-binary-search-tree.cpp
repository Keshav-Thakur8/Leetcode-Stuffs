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
    TreeNode* firstNode = NULL;
    TreeNode* secondNode = NULL;
    TreeNode* prev = NULL;
    void solve(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        solve(root->left);
        if(firstNode == NULL && (prev == NULL || prev->val >= root->val)) {
            firstNode = prev;
        }
        if(firstNode != NULL && prev->val >= root->val) {
            secondNode = root;
        }
        prev = root;
        
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        swap(firstNode->val, secondNode->val);
    }
};