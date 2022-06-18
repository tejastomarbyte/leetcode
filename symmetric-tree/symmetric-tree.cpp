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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>q1,q2;
        if(!root)return true;
        q1.push(root->left);
        q2.push(root->right);
        
        while(!q1.empty() && !q2.empty())
        {
            TreeNode *h1=q1.front(),*h2=q2.front();
            q1.pop();
            q2.pop();
            
            if(h1==nullptr && h2==nullptr)
                continue;
            
            if(h1==nullptr || h2==nullptr)
                return false;
            if(h1->val!=h2->val)
                return false;
            q1.push(h1->left);
            q1.push(h1->right);
            q2.push(h2->right);
            q2.push(h2->left);
            
        }
        return true;
        
    }
};