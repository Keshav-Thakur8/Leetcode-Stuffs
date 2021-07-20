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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        temp = head;
        ListNode* temp1 = head;
        for(int i=1 ; i<k ; i++) {
            temp = temp->next;
        }
        for(int i=1 ; i<cnt-k+1 ; i++) {
            temp1 = temp1->next;
        }
        swap(temp->val, temp1->val);
        return head;
    }
};