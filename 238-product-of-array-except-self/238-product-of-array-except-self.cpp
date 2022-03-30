class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suf(nums.size()),pre(nums.size());
        int pro=nums[0];
        pre[0]=pro;
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=pre[i-1]*nums[i];
        }
        pro=nums[nums.size()-1];
        suf[nums.size()-1]=pro;
        for(int i=nums.size()-2;i>=0;i--)
        {
            suf[i]=suf[i+1]*nums[i];
        }
        vector<int>ans(nums.size());
        ans[0]=suf[1];
        int n=nums.size();
        ans[nums.size()-1]=pre[n-2];
        for(int i=1;i<nums.size()-1;i++)
        {
            ans[i]=pre[i-1]*suf[i+1];
        }
        return ans;
        
    }
};