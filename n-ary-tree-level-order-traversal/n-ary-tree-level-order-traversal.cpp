/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) {
            return {};
        }
        vector<vector<int>> ans;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()) {
            int n = que.size();
            vector<int> curr_vec;
            for(int i=0 ; i<n ; i++) {
                Node* fnt = que.front();
                que.pop();
                curr_vec.push_back(fnt->val);
                //for a particular front node, push all its child in the queue
                for(int j=0 ; j<fnt->children.size() ; j++) {
                    que.push(fnt->children[j]);
                }
            }
            ans.push_back(curr_vec);
        }
        return ans;
    }
};