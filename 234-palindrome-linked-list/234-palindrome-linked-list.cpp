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
    ListNode* revList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(temp != NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL && head->next == NULL) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        //the moment fast is at the second last node or the last node
        //we will stop fast pointer
        //this will help in odd or even sized linked list
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = revList(slow->next);
        slow = slow->next;
        while(slow != NULL) {
            if(head->val != slow->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
        
    }
};