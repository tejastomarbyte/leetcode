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
        ListNode *h1=head,*h2=head;
        
        while(n--)
        {
            h2=h2->next;
            
        }
        if(h2==nullptr)
            return h1->next;
        
        
        while(h2->next!=nullptr)
        {
            h2=h2->next;
            h1=h1->next;
        }
        h1->next=h1->next->next;
        
        return head;
    }
};