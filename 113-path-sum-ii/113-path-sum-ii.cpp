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
    
    void f(vector<int> &v,vector<vector<int>> &ans,TreeNode *root,int t)
    {
        if(root==nullptr) return;
        if(!root->left && !root->right)
        {
            if(t-root->val==0)
            {
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
                return;
            }
        }
        
                v.push_back(root->val);
                f(v,ans,root->left,t-root->val);
                f(v,ans,root->right,t-root->val);
                v.pop_back();
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        f(v,ans,root,targetSum);
        return ans;
    }
};