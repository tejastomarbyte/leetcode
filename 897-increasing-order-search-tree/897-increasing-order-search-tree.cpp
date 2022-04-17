/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(vector<TreeNode*> &v,TreeNode* root)
    {
        if(!root)return;
        inorder(v,root->left);
        v.push_back(root);
        inorder(v,root->right);
    }
    /*TreeNode* create(vector<TreeNode*> v,int i)
    {
        if(i==v.size()-1)
        {
            TreeNode *t=v[i];
            t->right=t->left=nullptr;
            return t;
        }
        TreeNode *t=v[i];
        t->left=nullptr;
        t->right=create(v,i+1);
        return t;
    }*/
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(v,root);
        TreeNode* t=new TreeNode(v[0]->val);
        TreeNode *curr=t;
        for(int i=1;i<v.size();i++)
        {
            TreeNode *p=new TreeNode(v[i]->val);
            curr->right=p;
            curr=curr->right;
        }
        // t=create(v,0);
        return t;
    }
};