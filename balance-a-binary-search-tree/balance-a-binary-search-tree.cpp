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
    vector<int> res;
    void inOrder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
    
    TreeNode* sortedArraytoBST(int si, int ei) {
        if(si > ei) {
            return NULL;
        }
        int mid = (si+ei)/2;
        TreeNode* root = new TreeNode(res[mid]);
        root->left = sortedArraytoBST(si, mid-1);
        root->right = sortedArraytoBST(mid+1, ei);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return sortedArraytoBST(0, res.size()-1);
    }
};