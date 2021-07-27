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
    int ans = 0;
    int helper(TreeNode* root) {
        int level = 0;
        int lsum_so_far = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sum = 0;
            int n = q.size();
            while(n--) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            level++;
            if(sum > lsum_so_far) {
                ans = level;
            }
            lsum_so_far = max(lsum_so_far, sum);

        }
        return ans;
    }
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        helper(root);
        return ans;
    }
};