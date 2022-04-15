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
    int f(TreeNode* root,int maxi)
    {
        if(!root)
            return 0;
        int ans=0;
        if(root->val>=maxi)
        {
            maxi=root->val;
            ans=1;
        }
        int left=f(root->left,maxi);
        int right=f(root->right,maxi);
        return ans+left+right;
    }
    int goodNodes(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        return f(root,INT_MIN);
        
    }
};