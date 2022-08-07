class Solution {
public:
    bool f(vector<int>&nums,int i,vector<int>&dp)
    {
        if(i==nums.size())
            return true;
        if(dp[i]!=-1)return dp[i];
        if(i+1<nums.size() && nums[i]==nums[i+1])
        {
            if(f(nums,i+2,dp)) return dp[i]=true;
            if(i+2<nums.size() && nums[i+1]==nums[i+2])
                if(f(nums,i+3,dp))return dp[i]=true;
        }
        if(i+2<nums.size() and nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2])
            if(f(nums,i+3,dp))
                return dp[i]=true;
        
        return dp[i]=false;
    }
    bool validPartition(vector<int>& nums) {
        
        vector<int>dp(nums.size(),-1);
        return f(nums,0,dp);
    }
};