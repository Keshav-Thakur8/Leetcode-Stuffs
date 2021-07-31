/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = preOrder(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        string temp = "";
        for(char c:data) {
            if(c == '#') {
                root = buildTree(root, stoi(temp));
                temp = "";
            }
            else {
                temp += c;
            }
        }
        return root;
    }
    
    string preOrder(TreeNode* root) {
        if(root == NULL) {
            return "";
        }
        return to_string(root->val) + "#" + preOrder(root->left) + preOrder(root->right);
    }
    
    TreeNode* buildTree(TreeNode* root, int val) {
        if(root == NULL) {
            return new TreeNode(val);
        }
        if(val <= root->val) {
            root->left = buildTree(root->left, val);
        }
        if(val > root->val) {
            root->right = buildTree(root->right, val);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;