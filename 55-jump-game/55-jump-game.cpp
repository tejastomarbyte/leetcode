class Solution {
public:
    // bool f(vector<int> &nums,int i,vector<bool> &dp)
    // {
    //     if(i>=nums.size()-1)
    //         return true;
    //     if(nums[i]==0) return false;
    //     if(dp[i]) return dp[i];
    //     bool ans=false;
    //     for(int j=nums[i];j>=1;j--)
    //     {
    //         bool v=f(nums,i+j,dp);
    //         ans=(ans || v);
    //     }
    //     return dp[i]=ans;
    // }

    bool canJump(vector<int>& nums) {
        vector<bool>dp(nums.size()+1,false);
        dp[0]=true;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(i<=nums[j]+j && dp[j]) 
                { 
                    dp[i]=true;
                    break;
                }
                
            }
        }
        return dp[nums.size()-1];
        
    }
};