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
    void preorder(vector<int> &a,TreeNode* root)
    {
        
        if(!root)
            return;
        
        preorder(a,root->left);
        a.push_back(root->val);
        preorder(a,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> a;
        preorder(a,root);
        return a[k-1];
    }
};