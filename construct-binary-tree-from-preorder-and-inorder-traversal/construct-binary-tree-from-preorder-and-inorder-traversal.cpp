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
    TreeNode* solve(int currRoot, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder) {
        if(inEnd < inStart) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[currRoot]);
        int idx = 0;
        while(inorder[idx] != preorder[currRoot]) {
            idx++;
        }
        //this is very trivial
        root->left = solve(currRoot+1, inStart, idx-1, preorder, inorder);
        //this is indeed the most complex step
        root->right = solve(currRoot+idx-inStart+1, idx+1, inEnd, preorder, inorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(0, 0, inorder.size()-1, preorder, inorder);
    }
};