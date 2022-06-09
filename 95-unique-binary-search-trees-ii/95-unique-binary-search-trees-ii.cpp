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
    vector<TreeNode*> f(int s,int e)
    {
        vector<TreeNode*>v;
        if(s>e)
        {
            v.push_back(nullptr);
            return v;
        }
        if(s==e)
        {
            v.push_back(new TreeNode(s));
            return v;
        }
        for(int i=s;i<=e;i++)
        {
            vector<TreeNode*>l=f(s,i-1);
            vector<TreeNode*>r=f(i+1,e);
            
            for(auto j:l)
            {
                for(auto k:r)
                {
                    TreeNode* t=new TreeNode(i);
                    t->left=j;
                    t->right=k;
                    v.push_back(t);
                    
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
       
            return f(1,n);
    }
};