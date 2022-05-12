/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(!root)return nullptr;
        if(!root->left && !root->right)
        {
            root->next=nullptr;
            return root;
        }
        q.push(root->left);
        q.push(root->right);
        int count=2;
        while(!q.empty())
        {   Node *p=q.front();
            q.pop();
            if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            for(int i=1;i<count;i++)
            {
                Node *t=q.front();
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                p->next=t;
                p=t;
            }
            p->next=nullptr;
            count*=2;
        }
        return root;
    }
};