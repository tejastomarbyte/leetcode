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
    ListNode* partition(ListNode* head, int x) {
        ListNode* t=new ListNode(),*p=new ListNode(),*node=p;
        t->next=head;
        while(t->next)
        {
            if(t->next->val<x)
            {
                ListNode* temp=new ListNode(t->next->val);
                p->next=temp;
                p=temp;
            }
            t=t->next;
        }
        ListNode* n=head;
        while(n)
        {
            if(n->val>=x)
            {
                ListNode* temp=new ListNode(n->val);
                p->next=temp;
                p=temp;
            }
            n=n->next;
        }
        return node->next;
    }
};