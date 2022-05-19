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
    int pairSum(ListNode* head) {
        vector<int>v;
        ListNode*t=head;
        while(t)
        {
            v.push_back(t->val);
            t=t->next;
        }
        int i=(v.size()/2)-1,j=(v.size()/2);
        int maxi=INT_MIN;
        while(i>=0 && j<v.size())
        {
            maxi=max(v[i]+v[j],maxi);
            i--,j++;
        }
        return maxi;
    }
};