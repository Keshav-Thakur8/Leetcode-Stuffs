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
    void solve(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> curr_lvl;
            while(n--) {
                TreeNode* temp = q.front();
                q.pop();
                curr_lvl.push_back(temp->val);
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            res.push_back(curr_lvl);
        }
        
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