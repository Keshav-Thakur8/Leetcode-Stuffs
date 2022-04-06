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
    ListNode* reverseList(ListNode* head) {
        // ListNode* temp = head;
        // ListNode* op = NULL;
        // while(temp != NULL){
        //     ListNode* t1 = temp->next;
        //     temp->next = op;
        //     op = temp;
        //     temp = t1;
        // }
        // return op;
        
        //without extra space
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(temp != NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        //head = prev;
        return prev;
    }
};