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