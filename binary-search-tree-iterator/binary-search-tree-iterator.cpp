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
class BSTIterator {
public:
    vector<int> res;
    int idx = -1;
    void inOrder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }
    
    int next() {
        idx++;
        return res[idx];
    }
    
    bool hasNext() {
        if(idx < (int)res.size()-1) {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */