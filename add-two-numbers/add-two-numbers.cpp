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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //recursive
        if(l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        int x = l1->val + l2->val;
        ListNode* node = new ListNode(x%10);
        node->next = addTwoNumbers(l1->next, l2->next);
        if(x >= 10) {
            node->next = addTwoNumbers(node->next, new ListNode(1));
        }
        
        return node;
        // ListNode* ans = new ListNode();
        // ListNode* temp = ans;
        // int carry = 0;
        // while(l1!=0 || l2!=0 || carry!=0){
        //     int sum = 0;
        //     if(l1 != 0){
        //         sum += l1->val;
        //         l1 = l1->next;
        //     }
        //     if(l2 != 0){
        //         sum += l2->val;
        //         l2 = l2->next;
        //     }
        //     sum += carry;
        //     carry = sum/10;
        //     ListNode *node = new ListNode(sum%10);
        //     temp->next = node;
        //     temp = temp->next;
        // }
        // return ans->next;
    }
};