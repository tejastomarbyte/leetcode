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
        ListNode* t=head;
        
            
        while(n--)
        {
            t=t->next;
        }
        if(!t)
            return head->next;
        ListNode* h1=head;
        while(t->next)
        {
            h1=h1->next;
            t=t->next;
        }
        
        h1->next=h1->next->next;
        return head;
    }
};