/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //copy the list without random pointers
        unordered_map<Node*, Node*> m;
        Node* curr_old = head;
        Node dummy(-1);
        Node* new_list = &dummy, *prev = &dummy;
        while(curr_old != NULL){
            Node* temp = new Node(curr_old->val);
            prev->next = temp;
            //insert it in map
            m[curr_old] = temp;
            prev = prev->next;
            curr_old = curr_old->next;
        }
        
        //populate random pointers
        curr_old = head;
        Node* curr_new = new_list->next;
        while(curr_old != NULL){
            curr_new->random = m[curr_old->random];
            curr_old = curr_old->next;
            curr_new = curr_new->next;
        }
        return new_list->next;
    }
};