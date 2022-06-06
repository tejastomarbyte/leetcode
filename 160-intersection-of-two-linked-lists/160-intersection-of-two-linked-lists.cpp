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
        long long int l=0;
        while(t)
        {
            l++;
            t=t->next;
        }
        return l;
        
    }
    ListNode *getIntersectionNode(ListNode *n1, ListNode *n2) {
        int l1=length(n1),l2=length(n2);
        ListNode *t1=n1,*t2=n2;
        if(l1>l2)
        {
            while(l1>l2)
            {
                t1=t1->next;
                l1--;
            }
        }
        else if(l1<l2)
        {
            while(l1<l2)
            {
                t2=t2->next;
                l2--;
            }
        }
        while((t1!=t2) && t1!=nullptr)
        {
            t1=t1->next;
            t2=t2->next;
        }
        if(t1!=NULL && t2!=NULL)
            return t1;
        else 
            return nullptr;
        
        
        
        
    }
};