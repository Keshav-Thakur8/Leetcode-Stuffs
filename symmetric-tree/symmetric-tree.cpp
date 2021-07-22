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
    bool helper(TreeNode* l, TreeNode* r) {
        // Iterative Solution
        queue<TreeNode*> que;
        que.push(l);
        que.push(r);
        while(!que.empty()) {
            TreeNode* l1 = que.front();
            que.pop();
            TreeNode* r1 = que.front();
            que.pop();
            if(l1 == NULL && r1 == NULL) {
                continue;
            }
            if(l1 == NULL || r1 == NULL) {
                return false;
            }
            if(l1->val != r1->val) {
                return false;
            }
            que.push(l1->left);
            que.push(r1->right);
            que.push(l1->right);
            que.push(r1->left);
        }
        return true;
        
        // Recursive Solution
        // if(l == NULL && r == NULL) {
        //     return true;
        // }
        // if(l == NULL || r == NULL) {
        //     return false;
        // }
        // if(l->val != r->val) {
        //     return false;
        // }
        // return (helper(l->left,r->right) && helper(l->right, r->left));
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        return helper(root->left, root->right);
    }
};
