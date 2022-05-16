class Solution {
public:
    int countSquares(vector<vector<int>>& ma) {
        vector<vector<int>>dp(ma.size(),vector<int>(ma[0].size()));
        int n=ma.size(),m=ma[0].size();
        for(int i=0;i<n;i++)
            dp[i][0]=ma[i][0];
        for(int i=0;i<m;i++)
            dp[0][i]=ma[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                // int t1=INT_MAX,t2=INT_MAX,t3=INT_MAX;
                if(ma[i][j])
                    dp[i][j]=1+(min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])));
                else
                    dp[i][j]=0;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j])sum+=dp[i][j];
            }
        }
        return sum;
        
    }
};