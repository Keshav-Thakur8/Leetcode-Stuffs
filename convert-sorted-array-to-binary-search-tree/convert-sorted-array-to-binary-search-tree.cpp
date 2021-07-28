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
    TreeNode* build(vector<int>& nums, int si, int ei) {
        if(si > ei) {
            return NULL;
        }
        //if only one node is present
        if(si == ei) {
            return new TreeNode(nums[si]);
        }
        
        int mid = si + (ei-si)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, si, mid-1);
        root->right = build(nums, mid+1, ei);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
};