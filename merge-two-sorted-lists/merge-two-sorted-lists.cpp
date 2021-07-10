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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode help;
        ListNode *head = &help, *tail = &help;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val < temp2->val){
                tail->next = temp1;
                ListNode* t1 = temp1->next;
                temp1->next = NULL;
                temp1 = t1;
                tail = tail->next;
                
            }
            else{
                tail->next = temp2;
                ListNode* t2 = temp2->next;
                temp2->next = NULL;
                temp2 = t2;
                tail = tail->next;
            }
        }
        if(temp1 != NULL){
            tail->next = temp1;
        }
        if(temp2 != NULL){
            tail->next = temp2;
        }
        return head->next;
//         if(l1 == NULL){
//             return l2;
//         }
//         if(l2 == NULL){
//             return l1;
//         }
//         ListNode* final_head = NULL;
//         ListNode* final_tail = NULL;
//         if(l1->val <= l2->val){
//             final_head = l1;
//             final_tail = l1;
//             l1 = l1->next;
//         }
//         else{
//             final_head = l2;
//             final_tail = l2;
//             l2 = l2->next;
//         }
//         while(l1 != NULL && l2 != NULL){
//         if(l1->val <= l2->val)
//         {
//             final_tail->next = l1;
//             l1 = l1->next;
//             final_tail = final_tail->next;
            
//         }
//         else
//         {
//             final_tail->next = l2;
//             l2 = l2->next;
//             final_tail = final_tail->next;
            
//         }
//     }
//     if(l1 != NULL)
//     {
//         final_tail->next = l1;
//     }
//     if(l2 != NULL)
//     {
//         final_tail->next = l2;
//     }
//     return final_head;
        
        
    }
};