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
    map<int,int>m;
    int index;
    TreeNode* build(vector<int>preorder,int left,int right)
    {
        if(left>right)
            return nullptr;
        
        TreeNode* t=new TreeNode(preorder[index++]);
        
        t->left=build(preorder,left,m[t->val]-1);
        t->right=build(preorder,m[t->val]+1,right);
        
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index=0;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        
        return build(preorder,0,preorder.size()-1);
    }
};