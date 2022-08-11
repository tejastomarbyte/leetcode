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
    int index=0;
    void solve(TreeNode* root,vector<int> &v)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    void sovle1(TreeNode* &root,vector<int> v)
    {
        if(root==NULL)
        {
            return;
        }
        sovle1(root->left,v);
        root->val=v[index++];
        sovle1(root->right,v);
    }
    void recoverTree(TreeNode* root)
    {
        vector<int> v;
        solve(root,v);
        sort(v.begin(),v.end());
        sovle1(root,v);
    }
};