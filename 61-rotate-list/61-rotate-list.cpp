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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        int size =1;
        while(temp->next != NULL)
        {
            size++;
            temp = temp->next;
        }
        temp = head;
        for(int i=0 ; i<k%size ; i++) {
            while(temp->next->next != NULL) {
                temp = temp->next;
            }
            ListNode* temp1 = temp->next;
            temp->next = NULL;
            temp1->next = head;
            head = temp1;
            temp = head;
        }
        return head;
    }
};