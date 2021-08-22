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
    ListNode* findMid(ListNode* head) {
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        return slow;
    }
    
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* helper = new ListNode(0);
        ListNode* ptr = helper;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            }
            else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        if(l1 != NULL) {
            ptr->next = l1;
            //l1 = l1->next;
        }
        if(l2 != NULL) {
            ptr->next = l2;
            //l2 = l2->next;
        }
        
        return helper->next;
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* mid = findMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
        
    }
    
    // ListNode* merge(ListNode* l1,ListNode* l2){
    //     ListNode* sorted_temp = new ListNode(0);
    //     ListNode* current = sorted_temp;
    //     while(l1!=NULL && l2!=NULL){
    //         if(l1->val<l2->val){
    //             current->next = l1;
    //             l1 = l1->next;
    //         }else{
    //             current->next = l2;
    //             l2 = l2->next;
    //         }
    //         current = current->next;
    //     }
    //     if(l1!=NULL){
    //         current->next = l1;
    //         l1 = l1->next;
    //     }
    //     if(l2!=NULL){
    //         current->next = l2;
    //         l2 = l2->next;
    //     }
    //     return sorted_temp->next;
    // }
    // ListNode* sortList(ListNode* head) {
    //     if(head==NULL || head->next==NULL){
    //         return head;
    //     }
    //     ListNode* temp = head;
    //     ListNode* slow = head;
    //     ListNode* fast = head;
    //     while(fast!=NULL && fast->next!=NULL){
    //         temp = slow;
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     temp->next = NULL;
    //     ListNode* left_side = sortList(head);
    //     ListNode* right_side = sortList(slow);
    //     return merge(left_side,right_side);
    // }
};