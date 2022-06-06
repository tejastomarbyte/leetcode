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
    int length(ListNode* t)
    {
        int l=0;
        while(t)
        {
            t=t->next;
            l++;
        }
        return l;
    }
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int len1,len2;
        len1=length(head1);
        len2=length(head2);
        if(len1==0 || len2==0)return nullptr;
        if(len1>len2)
        {
            while(len1!=len2)
            {
                len1--;
                head1=head1->next;
            }
        }
        else
        {
            while(len1!=len2)
            {
                len2--;
                head2=head2->next;
            }
        } 
        while(head1 && head2 && head1!=head2)
        {
            
            head1=head1->next;
            head2=head2->next;
        }
        if(head1 && head2)
            return head1;
        else
            return nullptr;
        
    }
};