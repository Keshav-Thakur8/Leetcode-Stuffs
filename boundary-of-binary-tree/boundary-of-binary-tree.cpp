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
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }
    void leftBorder(TreeNode* root, vector<int> &res) {
        TreeNode* curr = root->left;
        while(curr != NULL) {
            if(isLeaf(curr) == false) {
                res.push_back(curr->val);
            }
            if(curr->left != NULL) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
    }
    void rightBorder(TreeNode* root, vector<int> &res) {
        vector<int> help;
        TreeNode* curr = root->right;
        while(curr != NULL) {
            if(isLeaf(curr) == false) {
                help.push_back(curr->val);
            }
            if(curr->right != NULL) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }
        for(int i=help.size()-1 ; i>=0 ; i--) {
            res.push_back(help[i]);
        }
    }
    void addLeaf(TreeNode* root, vector<int> &res) {
        if(isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        if(root->left) {
            addLeaf(root->left, res);
        }
        if(root->right) {
            addLeaf(root->right, res);
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        if(!isLeaf(root)) {
            res.push_back(root->val);
        }
        
        leftBorder(root, res);
        addLeaf(root, res);
        rightBorder(root, res);
        
        return res;
    }
};