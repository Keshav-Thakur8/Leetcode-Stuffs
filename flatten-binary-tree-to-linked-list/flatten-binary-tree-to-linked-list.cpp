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
    void flatten(TreeNode* root) {
        if(root != NULL) {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            
            TreeNode* t = root;
            while(t->right != NULL) {
                t = t->right;
            }
            
            t->right = temp;
            
            flatten(root->right);
        }
        return;
        
//         //base case
//         if(root == NULL || (root->left == NULL && root->right == NULL)) {
//             return;
//         }
        
//         //recursively flatten left and right subtree
//         if(root->left != NULL) {
//             flatten(root->left);
            
//             //store right subtree in temp
//             //make left subtree as right subtree
//             TreeNode* temp = root->right;
//             root->right = root->left;
//             root->left = NULL;
            
//             TreeNode* t = root;
//             while(t->right != NULL) {
//                 t = t->right;
//             }
            
//             t->right = temp;
//         }
//         flatten(root->right);
    }
};
