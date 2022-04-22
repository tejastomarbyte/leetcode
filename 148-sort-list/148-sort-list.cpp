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
    ListNode* sortList(ListNode* head) {
        // vector<int>v;
        // ListNode* t=new ListNode(head->val);
        // while(t)
        // {
        //     v.push_back(t->val);
        //     t=t->next;
        // }
        // sort(v.begin(),v.end());
        // ListNode *h=new ListNode();
        // ListNode* x=new ListNode(v[0]);
        // h->next=x;
        // t=x;
        // for(int i=1;i<v.size();i++)
        // {
        //     ListNode* p=new ListNode(v[i]);
        //     t->next=p;
        //     t=p;
        // }
        // t->next=nullptr;
        // return h->next;
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* curr = head;
        ListNode* temp = new ListNode();
        ListNode* newnode = temp;
        ListNode* prev;
        prev = curr;
        
        vector<int> v;
        while(curr!=NULL){
            v.push_back(curr->val);
            curr= curr->next;
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++){
            newnode->next = new ListNode(v[i]);
            newnode = newnode->next;
        }
        return temp->next;
    }
};