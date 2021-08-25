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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt;
        while(curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        //monotonic stack
        ListNode* h = reverseList(head);
        stack<int>st;
        vector<int>v;
        while(h){
            while(!st.empty() && h->val>=st.top()) {
                st.pop();
            }
            v.push_back(st.empty() ? 0:st.top());
            st.push(h->val);
            h = h->next;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};