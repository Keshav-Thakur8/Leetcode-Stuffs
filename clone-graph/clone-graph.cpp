/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void solve(Node* start, unordered_map<Node*, Node*> &mp) {
        Node* new_node = new Node(start->val);
        mp[start] = new_node;
        
        for(auto& nbr : start->neighbors) {
            if(mp.find(nbr) != mp.end()) {
                new_node->neighbors.push_back(mp[nbr]);
            }
            else {
                solve(nbr, mp);
                new_node->neighbors.push_back(mp[nbr]);
                
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) {
            return NULL;
        }
        unordered_map<Node*, Node*> mp;
        
        solve(node, mp);
        
        return mp[node];
    }
};