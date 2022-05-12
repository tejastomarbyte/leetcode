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
    void f(TreeNode* root,string &s)
    {
        if(!root)
            return;
        s.push_back('(');
        s+=to_string(root->val);
        if(!root->left && root->right)
        {
            s.push_back('(');
            s.push_back(')');
        }
        else
            f(root->left,s);
        
        if(root->right)f(root->right,s);
        s.push_back(')');
    }
    string tree2str(TreeNode* root) {
        string s;
        if(!root)return s;
        f(root,s);
        
        return s.substr(1,s.length()-2);
    }
};