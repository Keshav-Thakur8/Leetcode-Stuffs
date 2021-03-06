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
        //corner case
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* temp = head;
        //length of LL
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        
        //find the position which has to be deleted
        int pos = cnt-n+1;
        
        //point to that node
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
        
        //connect
        prev->next = prev->next->next;
        return head;
    }
};