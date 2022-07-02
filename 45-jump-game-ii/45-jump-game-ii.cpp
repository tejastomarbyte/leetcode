class Solution {
public:
    int f(vector<int>&nums,int i,vector<int> &dp)
    {
        if(i>=nums.size()-1)
            return 0;
        if(nums[i]==0)
            return 1e8;
        if(dp[i]!=-1)return dp[i];
        int ans=1e8;
        for(int j=nums[i];j>=1;j--)
        {
            int l=1+f(nums,i+j,dp);
            ans=min(ans,l);
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        
        return f(nums,0,dp);
    }
};