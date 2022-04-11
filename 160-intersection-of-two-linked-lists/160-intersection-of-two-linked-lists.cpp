/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // // Hashmap Approach
        // unordered_map<ListNode*, int> mp;
        // while(headA != NULL) {
        //     mp[headA]++;
        //     headA = headA->next;
        // }
        // while(headB != NULL) {
        //     if(mp.find(headB) != mp.end()) {
        //         return headB;
        //     }
        //     headB = headB->next;
        // }
        // return NULL;
        
        
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1 != p2){
            if(p1 == NULL){
                p1 = headB;
            }
            else if(p2 == NULL){
                p2 = headA;
            }
            else{
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return p1;
    }
};