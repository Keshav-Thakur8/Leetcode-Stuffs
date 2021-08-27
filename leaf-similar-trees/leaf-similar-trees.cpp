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
    void solve(TreeNode* nodes, vector<int> &lvs) {
        if(nodes == NULL) {
            return;
        }
        if(nodes->left == NULL && nodes->right == NULL) {
            lvs.push_back(nodes->val);
        }
        solve(nodes->left, lvs);
        solve(nodes->right, lvs);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> lvs1;
        vector<int> lvs2;
        solve(root1, lvs1);
        solve(root2, lvs2);
        
        return lvs1 == lvs2;
    }
};