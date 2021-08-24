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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* pre = prev;
        while(temp != NULL) {
            if(temp->val == val) {
                pre->next = temp->next;
                temp = temp->next;
            }
            else {
                pre = temp;
                temp = temp->next;
            }
        }
        return prev->next;
    }
};