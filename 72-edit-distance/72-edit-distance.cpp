class Solution {
public:
    int f(string x,string y,int i,int j,vector<vector<int>>&dp)
    {
        if(i==0)
            return j;
        if(j==0)
            return i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(x[i-1]==y[j-1])
        {
            return dp[i-1][j-1]=f(x,y,i-1,j-1,dp);
        }
        
        else
        {
            return dp[i][j]=1+min(min(f(x,y,i-1,j,dp),f(x,y,i,j-1,dp)),f(x,y,i-1,j-1,dp));
        }
    }
    int minDistance(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=i;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
       
    }
};