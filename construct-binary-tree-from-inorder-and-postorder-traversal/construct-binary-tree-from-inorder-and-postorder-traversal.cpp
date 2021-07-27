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
    TreeNode* solve(int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder, int postStart, int postEnd) {
        if(inEnd < inStart) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int idx = 0;
        while(inorder[idx] != postorder[postEnd]) {
            idx++;
        }
        //this is very complex part
        root->left = solve(inStart, idx-1, inorder, postorder, postStart, postStart+idx-inStart-1);
        root->right = solve(idx+1, inEnd, inorder, postorder, postStart+idx-inStart, postEnd-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(0, inorder.size()-1, inorder, postorder, 0, postorder.size()-1);
    }
};