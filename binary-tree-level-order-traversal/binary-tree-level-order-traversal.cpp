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
    vector<vector<int>> res;
    vector<vector<int>> solve(TreeNode* root) {
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()) {
            int n = pendingNodes.size();
            vector<int> curr_lvl;
            while(n--) {
                TreeNode* temp = pendingNodes.front();
                pendingNodes.pop();
                curr_lvl.push_back(temp->val);
                if(temp->left) {
                    pendingNodes.push(temp->left);
                }
                if(temp->right) {
                    pendingNodes.push(temp->right);
                }
            }
            res.push_back(curr_lvl);
        }
        return res;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) {
            return res;
        }
        else {
            solve(root);
        }
        return res;
    }
};