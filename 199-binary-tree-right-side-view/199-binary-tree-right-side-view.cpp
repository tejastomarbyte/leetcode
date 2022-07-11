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
    vector<int> rightSideView(TreeNode* root) {
        int curlev=0,maxlev=-1;
        
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        if(!root)
            return ans;
        while(!q.empty())
        {
            int size=q.size();
            
            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();
                if(maxlev<curlev)
                {
                    maxlev=curlev;
                    ans.push_back(node->val);
                }
                
                
                if(node->right)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);
                
                
            }
            curlev++;
        }
        return ans;
    }
};