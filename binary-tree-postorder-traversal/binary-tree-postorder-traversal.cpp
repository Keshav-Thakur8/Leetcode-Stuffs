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
    // //using 2 stack
    // void helper(TreeNode* root, vector<int> &res) {
    //     if(root == NULL) {
    //         return;
    //     }
    //     stack<TreeNode*> st1, st2;
    //     st1.push(root);
    //     while(!st1.empty()) {
    //         root = st1.top();
    //         st1.pop();
    //         st2.push(root);
    //         if(root->left) {
    //             st1.push(root->left);
    //         }
    //         if(root->right) {
    //             st1.push(root->right);
    //         }
    //     }
    //     while(!st2.empty()) {
    //         res.push_back(st2.top()->val);
    //         st2.pop();
    //     }
    // }
    
    //using single stack
    void helper(TreeNode* root, vector<int> &res) {
        if(root == NULL) {
            return;
        }
        stack<TreeNode*> st;
        TreeNode* current = root;  
        while(current != NULL || !st.empty()) {
            if(current != NULL){
                st.push(current);
                current = current->left;
            }else{
                TreeNode* temp = st.top()->right;
                if (temp == NULL) {
                    temp = st.top();
                    st.pop(); 
                    res.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop(); 
                        res.push_back(temp->val);
                    }
                } 
                else {
                    current = temp;
                }
            }
        } 
    }
    
    // //recursive
    // void helper(TreeNode* root, vector<int> &res) {
    //     if(root == NULL) {
    //         return;
    //     }
    //     helper(root->left, res);
    //     helper(root->right, res);
    //     res.push_back(root->val);
    // }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};