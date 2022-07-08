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
    int f(TreeNode* root,map<TreeNode*,int>&m)
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return root->val;
        
        if(m.count(root))
            return m[root];
        
        int l=0,r=0;
        
        if(root->left)
        {
            l=f(root->left->left,m)+f(root->left->right,m);
        }
        if(root->right)
        {
            r=f(root->right->left,m)+f(root->right->right,m);
        }
        
        return m[root]=max(root->val+l+r,f(root->left,m)+f(root->right,m));
    }
    int rob(TreeNode* root) {
        map<TreeNode*,int>m;
        return f(root,m);
    }
};