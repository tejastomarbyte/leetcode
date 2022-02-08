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
    void f(vector<string> &ans,TreeNode* root,string &s)
    {
        if(!root)return;
        if(!root->left && !root->right)
        {   string t=to_string(root->val);
            ans.push_back(s+t);
            return;
        }
        string t=s+to_string(root->val)+"->";
        f(ans,root->left,t);
        f(ans,root->right,t);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;
        f(ans,root,s);
        return ans;
    }
};