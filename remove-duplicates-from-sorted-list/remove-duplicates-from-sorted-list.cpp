/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //corner case
        //thora fast hai
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != NULL) {
            if(prev->val == curr->val) {
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
        
        // ListNode* temp = head;
        // while(temp != NULL && temp->next != NULL) {
        //     if(temp->val == temp->next->val) {
        //         temp->next = temp->next->next;
        //         temp = temp->next;
        //         //this will help in the case in which all elements of the list are same
        //         temp = head;
        //     }
        //     else {
        //         temp = temp->next;
        //     }
        // }
        // return head;
    }
};
