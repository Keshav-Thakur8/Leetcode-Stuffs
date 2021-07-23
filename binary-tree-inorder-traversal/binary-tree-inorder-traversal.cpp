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
    //iterative
    void solve(TreeNode* root, vector<int> &res) {
        stack<TreeNode*> st;
        while(root != NULL || !st.empty()) {
            while(root != NULL) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }
    }
    // //recursive
    // void solve(TreeNode* root, vector<int> &res) {
    //     if(root == NULL) {
    //         return;
    //     }
    //     solve(root->left,res);
    //     res.push_back(root->val);
    //     solve(root->right,res);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root, res);
        return res;
    }
};