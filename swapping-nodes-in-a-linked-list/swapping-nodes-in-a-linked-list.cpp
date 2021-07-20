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
        //We traverse the list until we reach the kth node.
        //Then we set kth to that node to remember it, set ptr2 to head and continue traversing the list, while we               //move both ptr1 and ptr2.
        //When ptr1 reaches the end - ptr2 is on the (n-k)th node.
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        ListNode* kth = NULL;
        while(--k != 0) {
            temp1 = temp1->next;
        }
        kth = temp1;
        temp1 = temp1->next;
        while(temp1 != NULL) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        swap(temp2->val, kth->val);
        return head;
        // ListNode* temp = head;
        // int cnt = 0;
        // while(temp != NULL){
        //     cnt++;
        //     temp = temp->next;
        // }
        // temp = head;
        // ListNode* temp1 = head;
        // for(int i=1 ; i<k ; i++) {
        //     temp = temp->next;
        // }
        // for(int i=1 ; i<cnt-k+1 ; i++) {
        //     temp1 = temp1->next;
        // }
        // swap(temp->val, temp1->val);
        // return head;
    }
};
