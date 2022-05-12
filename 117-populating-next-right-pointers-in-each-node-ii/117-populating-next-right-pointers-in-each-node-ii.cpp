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
        if(!root)return root;
        if(!root->left && !root->right)
        {
            root->next=nullptr;
            return root;
        }
        queue<Node*>q;
        root->next=nullptr;
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
        while(!q.empty())
        {
            int size=q.size();
            Node* temp=q.front();
            q.pop();
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            for(int i=0;i<size-1;i++)
            {   
                Node* t=q.front();
                q.pop();
                
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                temp->next=t;
                temp=t;
            }
            temp->next=nullptr;
        }
        return root;
    }
};