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
    int f(TreeNode* root,int sum)
    {   if(!root)
        return 0;
        if(!root->left && !root->right)
        {
            return sum*2+root->val;
        }
        
        int left=0;
        if(root->left)
        left=f(root->left,sum*2+root->val);
        int right;
        if(root->right);
        right=f(root->right,sum*2+root->val);
        
        return left+right;
        
        
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans=f(root,0);
        return ans;
    }
};