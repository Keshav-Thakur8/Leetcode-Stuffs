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
//     void swapnode(TreeNode** node1, TreeNode** node2) {
//         TreeNode* temp = *node1;
//         *node1 = *node2;
//         *node2 = temp;
//     }
    
//     void solve(TreeNode* root) {
//         if(root == NULL) {
//             return;
//         }
//         swapnode(&root->left, &root->right);
//         solve(root->left);
//         solve(root->right);
//     }
    TreeNode* invertTree(TreeNode* root) {
        // solve(root);
        // return root;
        if(root == NULL) {
            return NULL;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
        
    }
};