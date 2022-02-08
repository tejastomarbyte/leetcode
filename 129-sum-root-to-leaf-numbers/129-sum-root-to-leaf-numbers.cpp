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
    void f(vector<string> &s,string t,TreeNode* root)
    {
        if(!root)return;
        if(!root->left && !root->right)
        {
            string temp=t;
            string m=to_string(root->val);
            temp+=m;
            s.push_back(temp);
        }
        
        string temp=t;
        string m=to_string(root->val);
        temp+=m;
        f(s,temp,root->left);
        f(s,temp,root->right);
    }
    int sumNumbers(TreeNode* root) {
        vector<string> s;
        string t;
        f(s,t,root);
        int sum=0;
        for(auto it:s)
        {
             string temp=it;
             stringstream a(it);
             int x = 0;
             a >> x;
             sum+=x; 
        }
        return sum;
    }
};