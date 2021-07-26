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
    vector<double> res;
    vector<double> solve(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            long sum = 0;
            long count = 0; // this will count the nodes at each level
            int n = q.size();
            while(n--) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                count++;
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
                
            }
            res.push_back((double)sum/count);
        }
        return res;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL) {
            return res;
        }
        else {
            solve(root);
        }
        return res;
    }
};