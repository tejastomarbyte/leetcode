class Solution {
public:
    int f(vector<int>n,vector<int>&dp,int i)
    {
        if(i==n.size()-1)
        {
            return n[i];
        }
        if(i>=n.size())
            return 0;
        if(dp[i]!=-1)return dp[i];
        int l=n[i]+f(n,dp,i+2);
        int r=f(n,dp,i+1);
        return dp[i]=max(l,r);
    }
    int rob(vector<int>& nums) {
        int ans=0;
        vector<int>dp(nums.size(),-1);
        return f(nums,dp,0);
    }
};