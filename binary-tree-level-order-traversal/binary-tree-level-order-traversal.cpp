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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        vector<int> curr_vec;
        while(!pendingNodes.empty()){
            TreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            if(front == NULL){
                ans.push_back(curr_vec);
                curr_vec.resize(0);
                if(!pendingNodes.empty())
                    pendingNodes.push(NULL);
                
            }else{
                curr_vec.push_back(front->val);
                if(front->left)
                    pendingNodes.push(front->left);
                if(front->right)
                    pendingNodes.push(front->right);
            }
        }
        return ans;
        
        
    }
};
