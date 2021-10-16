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
    //helper for finding height
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        int left_h = height(root->left);
        int right_h = height(root->right);
        return max(left_h, right_h)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //base case
        if(root == NULL){
            return 0;
        }
        //Three cases:
        //1. Diameter passes through root
        int d1 = height(root->left) + height(root->right);
        
        //2. Diameter exist in left subtree
        int d2 = diameterOfBinaryTree(root->left);
        
        //3. Diameter exist in right subtree
        int d3 = diameterOfBinaryTree(root->right);
        
        return max(d1, max(d2, d3));
        
    }
};