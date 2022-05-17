/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* o,TreeNode* c,TreeNode* tar,TreeNode* &t)
    {
        if(!o || !c)return;
        if(o->val==tar->val)
        {
            t=c;
        }
        
        dfs(o->left,c->left,tar,t);
        dfs(o->right,c->right,tar,t);
    }
    
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* tar) {
        if(!o)return nullptr;
        TreeNode* t;
        dfs(o,c,tar,t);
        return t;
    }
};