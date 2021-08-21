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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before_head = new ListNode(0);
        //before_head->next = NULL;
        ListNode* bh = before_head;
        
        ListNode* after_head = new ListNode(0);
        //after_head->next = NULL;
        ListNode* ah = after_head;
        
        while(head != NULL) {
            if(head->val < x) {
                bh->next = head;
                bh = bh->next;
            }
            else {
                ah->next = head;
                ah = ah->next;
            }
            head = head->next;
        }
        ah->next = NULL;
        
        //merge process
        bh->next = after_head->next;
        
        return before_head->next;
    }
};