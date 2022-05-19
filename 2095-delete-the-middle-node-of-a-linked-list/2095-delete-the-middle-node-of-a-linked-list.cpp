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
    ListNode* deleteMiddle(ListNode* head) {
        
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        ListNode* slow=head,*fast=head,*t=head;
        while(fast && fast->next)
        {
            t=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==head)
            return nullptr;
        t->next=slow->next;
        return head;
    }
    
};