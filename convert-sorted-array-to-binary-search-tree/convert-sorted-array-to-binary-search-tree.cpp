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
    TreeNode* f(vector<int>&nums,int i,int j)
    {
        if(i>j)
            return nullptr;
        
        
        int mid=(i+j)/2;
        
        TreeNode* h=new TreeNode(nums[mid]);
        h->left=f(nums,i,mid-1);
        h->right=f(nums,mid+1,j);
        return h;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return nullptr;
        return f(nums,0,nums.size()-1);
        
        
    }
};