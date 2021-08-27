/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) {
            return root;
        }
        queue<Node*> q;
        q.push(root);
        Node* fnt;
        while(!q.empty()) {
            int n = q.size();
            for(int i=0 ; i<n ; i++) {
                fnt = q.front();
                q.pop();
                if(fnt->left) {
                    q.push(fnt->left);
                }
                if(fnt->right) {
                    q.push(fnt->right);
                }
                if(i != n-1) {
                    fnt->next = q.front();
                }
            }
            fnt->next = NULL;
        }
        return root;
        
        
        // Node* level = root;
        // while(level != NULL) {
        //     Node* curr = level;
        //     while(curr != NULL) {
        //         if(curr->left) {
        //             curr->left->next = curr->right;
        //         }
        //         if(curr->right && curr->next && curr->next->left) {
        //             curr->right->next = curr->next->left;
        //         }
        //         else {
        //             curr->right->next = curr->next->right;
        //         }
        //         curr = curr->next;
        //     }
        //     level = level->left;
        // }
        // return root;
    }
};