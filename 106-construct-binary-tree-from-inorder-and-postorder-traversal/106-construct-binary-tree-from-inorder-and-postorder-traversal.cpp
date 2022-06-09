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
    TreeNode* build(vector<int>postorder,int left,int right)
    {
        if(left>right)
            return nullptr;
        
        TreeNode* t=new TreeNode(postorder[index--]);
        t->right=build(postorder,m[t->val]+1,right);
        t->left=build(postorder,left,m[t->val]-1);
        
        return t;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index=postorder.size()-1;
        
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        
        return build(postorder,0,postorder.size()-1);
    }
};