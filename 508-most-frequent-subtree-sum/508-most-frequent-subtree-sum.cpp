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
    int f(TreeNode* root,vector<int> &ans)
    {
        if(!root)return 0;
        
        int temp=root->val+f(root->left,ans)+f(root->right,ans);
        ans.push_back(temp);
        
        return temp;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        int sum=0;
        f(root,ans);
        unordered_map<int,int>m;
        for(auto it:ans)
            m[it]++;
        int maxi=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            maxi=max(maxi,it->second);
        }
        vector<int>fill;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second==maxi)
                fill.push_back(it->first);
        }
        return fill;
    }
};