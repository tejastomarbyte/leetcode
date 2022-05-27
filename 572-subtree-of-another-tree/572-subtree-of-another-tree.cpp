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
    bool ischeck(TreeNode* root,TreeNode* sub)
    {
        if(!root && !sub)return true;
        if(!root || !sub)return false;
        
        
    return(( root->val==sub->val) && ischeck(root->right,sub->right) && ischeck(root->left,sub->left));
       
    }
    
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(!root && !sub)return true;
        if(!root || !sub)return false;
        
        if(ischeck(root,sub))return true;
        return isSubtree(root->left,sub) || isSubtree(root->right,sub);
    }
};