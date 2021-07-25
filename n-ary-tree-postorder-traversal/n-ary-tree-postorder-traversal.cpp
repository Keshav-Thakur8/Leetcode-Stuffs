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
    //iterative
    void solve(Node* root, vector<int>& res) {
        if(root == NULL) {
            return;
        }
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node* fnt = st.top();
            st.pop();
            for(int i=0 ; i<fnt->children.size() ; i++) {
                st.push(fnt->children[i]);
            }
            res.push_back(fnt->val);
        }
        reverse(res.begin(), res.end());
    }
//     //recursive
//     void solve(Node* root, vector<int>& res) {
//         if(root == NULL) {
//             return;
//         }
//         for(int i=0 ; i<root->children.size() ; i++) {
//             solve(root->children[i], res);
//         }
//         res.push_back(root->val);
        
//     }
    
    vector<int> postorder(Node* root) {
        vector<int> res;
        solve(root, res);
        return res;
    }
};
