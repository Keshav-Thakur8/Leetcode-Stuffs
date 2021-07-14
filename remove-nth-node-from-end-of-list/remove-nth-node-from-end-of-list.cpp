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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        int pos = cnt-n+1;
        if(pos <= 0){
            return head;
        }
        if(pos == 1){
            temp = head;
            head = head->next;
            return head;
        }
        ListNode* prev = head;
        for(int i=1 ; i<pos-1 ; i++){
            prev = prev->next;
        }
        //ListNode* del = prev->next;
        prev->next = prev->next->next;
        return head;
    }
};