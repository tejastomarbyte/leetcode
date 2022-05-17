class Solution {
public:
    long long f(vector<int>p,int i,int buy,int tr,vector<vector<vector<long long>>>&dp)
    {
        if(i==p.size())
            return 0;
        if(tr==2)
            return 0;
        if(dp[i][buy][tr]!=-1)return dp[i][buy][tr];
        long long profit;
        if(buy)
        {
            profit=max(-1*p[i]+f(p,i+1,0,tr,dp),f(p,i+1,1,tr,dp));
        }
        else
        {
            profit=max(p[i]+f(p,i+1,1,tr+1,dp),f(p,i+1,0,tr,dp));
        }
        return dp[i][buy][tr]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<long long>>>dp(prices.size()+1,vector<vector<long long>>(2,vector<long long>(3,0)));
        int n=prices.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                for(int k=1;k<=2;k++)
                {
                    
                    if(j)
                    {
                        dp[i][j][k]=max(-1*prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }
                    else
                    {
                        dp[i][j][k]=max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][2];
        
    }
};