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
    int maxlev=0;
    void f(TreeNode* root,int curlev,vector<int>&ans)
    {
        if(!root)return;
        if(curlev>maxlev)//current level is more than the maximum level we have transversed
        {
            ans.push_back(root->val);
            maxlev++;
        }
        curlev+=1;
        f(root->right,curlev,ans);
        f(root->left,curlev,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int cur=1,maxi=0;
        f(root,cur,ans);
        return ans;
    }
};