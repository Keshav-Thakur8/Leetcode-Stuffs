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
    vector<TreeNode*> solve(int l, int r) {
        if(l > r) {
            return {NULL};
        }
        if(l == r) {
            return {(new TreeNode(l))};
        }
        vector<TreeNode*> ans;
        for(int i=l ; i<=r ; i++) {
            //i is parent
            //for every i create left and right subtree
            
            //left subtree [l...i-1]
            vector<TreeNode*> leftNode, rightNode;
            leftNode = solve(l, i-1);
            //right subtree [i+1...r]
            rightNode = solve(i+1, r);
            
            //these two loops will create all possible left and right subtree
            for(int j=0 ; j<leftNode.size() ; j++) {
                for(int k=0 ; k<rightNode.size() ; k++) {
                    TreeNode* newNode = new TreeNode(i);
                    newNode->left = leftNode[j];
                    newNode->right = rightNode[k];
                    ans.push_back(newNode);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) {
            return {};
        }
        return solve(1,n);
    }
};