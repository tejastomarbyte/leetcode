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
    unordered_map<int,int>m;
    int maxi=INT_MIN;
    int f(TreeNode* root)
    {
        if(!root)return 0;
        
        int temp=root->val+f(root->left)+f(root->right);
        m[temp]++;
        maxi=max(maxi,m[temp]);
        return temp;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        int sum=0;
        f(root);
        for(auto it=m.begin();it!=m.end();it++)if(it->second==maxi)ans.push_back(it->first);
        return ans;
    }
};