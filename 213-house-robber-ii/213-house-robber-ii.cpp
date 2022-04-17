class Solution {
public:
    
    int f(vector<int>n,vector<int>&dp,bool flag,int i)
    {
        if(flag)
        {
            if(i>=n.size()-1)
                return 0; 
        }
        else if(flag==false)
        {
            if(i==n.size()-1)
                return n[i];
            else if(i>n.size()-1)
                return 0;
        }
        if(dp[i]!=-1)return dp[i];
        
        int l=n[i]+f(n,dp,flag,i+2);
        int r=f(n,dp,flag,i+1);
        
        return dp[i]=max(l,r);
        
    }
    int rob(vector<int>& nums) {
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        if(nums.size()==1)
            return nums[0];
        return max(f(nums,dp1,true,0),f(nums,dp2,false,1));
    }
};