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
    // void solve(TreeNode* root, int curr_sum, int targetSum, unordered_map<int, int> mp, int &cnt) {
    //     if(root == NULL) {
    //         return;
    //     }
    //     curr_sum += root->val;
    //     if(mp.count(curr_sum-targetSum)) {
    //         cnt += mp[curr_sum-targetSum];
    //     }
    //     mp[curr_sum]++;
    //     solve(root->left, curr_sum, targetSum, mp, cnt);
    //     solve(root->right, curr_sum, targetSum, mp, cnt);
    //     return;
    // }
    void solver(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return;
        }
        if(root->val == targetSum) {
            ans++;
        }
        solver(root->left, targetSum-root->val);
        solver(root->right, targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        // unordered_map<int, int> mp;
        // mp[0] = 1;
        // int cnt = 0;
        // solve(root, 0, targetSum, mp, cnt);
        // return cnt;
        if(root != NULL) {
            solver(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
         
        
        // if(root == NULL) {
        //     return 0;
        // }
        // int cnt = 0;
        // if(root->val == targetSum && root->left == NULL && root->right == NULL) {
        //     return 1;
        // }
        // if(root->val == targetSum) {
        //     cnt++;
        // }
        // if(root->val > targetSum) {
        //     pathSum(root->left, targetSum);
        //     pathSum(root->right, targetSum);
        // }
        // else {
        //     pathSum(root->left, targetSum-root->val);
        //     pathSum(root->right, targetSum-root->val);
        // }
        // return cnt;
    }
};
