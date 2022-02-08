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
    void f(string &t,vector<string> &s, TreeNode* root)
    {
        if(!root)return;
        if(!root->left && !root->right)
        {   string temp=t;
            temp.push_back((char)97+root->val);
            reverse(temp.begin(),temp.end());
            s.push_back(temp);
            return;
        }
        string temp=t;
        temp.push_back((char)97+root->val);
        // reverse(temp.begin(),temp.end());
        f(temp,s,root->left);
        f(temp,s,root->right);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> s;
        string t;
        f(t,s,root);
        sort(s.begin(),s.end());
        return s[0];
    }
};