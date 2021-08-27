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
    //vector<int> res;
    // void help(TreeNode* root) {
    //     if(root == NULL) {
    //         return;
    //     }
    //     res.push_back(root->val);
    //     help(root->right);
    // }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i=0 ; i<n ; i++) {
                TreeNode* fnt = q.front();
                q.pop();
                if(i == n-1) {
                    res.push_back(fnt->val);
                }
                if(fnt->left) {
                    q.push(fnt->left);
                }
                if(fnt->right) {
                    q.push(fnt->right);
                }
            }
        }
        return res;
        
        
        
//         if(root == NULL) {
//             return res;
//         }
//         help(root);
        
//         return res;
    }
};