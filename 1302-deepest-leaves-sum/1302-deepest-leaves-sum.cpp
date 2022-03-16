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
    int height(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        
        int l=height(root->left);
        int r=height(root->right);
        
        return 1+max(l,r);
    }
    int sum(TreeNode* root,int cur,int h)
    {
        
        if(root==nullptr)
        {
            return 0;
        }
        if(cur==h)
        {
            return root->val;
            
        }
        
        int l=sum(root->left,cur+1,h);
        int r=sum(root->right,cur+1,h);
        
        return l+r;
    }
    int deepestLeavesSum(TreeNode* root) {
        int h=height(root);
        return sum(root,1,h);
    }
};