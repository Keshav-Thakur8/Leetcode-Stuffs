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
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        //use sentinal head
        ListNode* senti = new ListNode(0);
        senti->next = head;
        ListNode* prev = senti;
        while(head != NULL) {
            if(head->next != NULL && head->val == head->next->val) {
                while(head->next != NULL && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
                
            }
            else {
                prev = prev->next;
            }
            head = head->next;
        }
        return senti->next;
        
        
//         ListNode* ass = NULL;
//         ListNode* prev = head;
//         ListNode* curr = head->next;
//         while(curr != NULL) {
//             if(prev->val == curr->val) {
//                 prev = curr;
//                 curr = curr->next;
//                 if(prev->val == curr->val) {
//                     continue;
//                 }
//                 else{
//                     ass->next = curr;
//                     prev = curr;
//                     curr = curr->next;
//                 }
//             }
//             else {
                
//                 ass = prev;
//                 prev = curr;
//                 curr = curr->next;
                
//             }
//         }
//         return head;
    }
};