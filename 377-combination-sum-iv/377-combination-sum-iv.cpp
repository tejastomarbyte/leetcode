class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        vector<unsigned int>dp(t+1);
        dp[0]=1;
        
        for(int i=1;i<=t;i++)
        {
            for(auto j:nums)
            {
                if(j<=i)
                    dp[i]+=dp[i-j];
            }
        }
        return dp[t];
    }
};