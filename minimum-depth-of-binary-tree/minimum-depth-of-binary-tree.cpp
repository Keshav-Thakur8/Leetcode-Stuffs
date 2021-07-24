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
    int minDepth(TreeNode* root) {
        //iterative
        if(root == NULL) {
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()) {
            res++;
            int n = q.size();
            for(int i=0 ; i<n ; i++) {
                root = q.front();
                q.pop();
                if(root->left == NULL && root->right == NULL) {
                    return res;
                }
                if(root->left) {
                    q.push(root->left);
                }
                if(root->right) {
                    q.push(root->right);
                }
            }
        }
        return -1;
//         //recursive solution
//         if(root == NULL){
//             return 0;
//         }
//         int l_height = 1+minDepth(root->left);
//         int r_height = 1+minDepth(root->right);
        
//         if(l_height==1 || r_height==1){
//             return max(l_height, r_height);
//         }
//         return min(l_height, r_height);
    }
};
