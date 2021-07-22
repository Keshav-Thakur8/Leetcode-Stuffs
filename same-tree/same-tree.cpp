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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Iterative Solution
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while(!que.empty()) {
            TreeNode* l = que.front();
            que.pop();
            TreeNode* r = que.front();
            que.pop();
            if(l == NULL && r == NULL) {
                continue;
            }
            if(l == NULL || r == NULL) {
                return false;
            }
            if(l->val != r->val) {
                return false;
            }
            que.push(l->left);
            que.push(r->left);
            que.push(l->right);
            que.push(r->right);
        }
        return true;
        
        
        // Recursive Solution
        // if(p == NULL && q == NULL) {
        //     return true;
        // }
        // if(p == NULL || q == NULL) {
        //     return false;
        // }
        // if(p->val != q->val) {
        //     return false;
        // }
        // return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};
