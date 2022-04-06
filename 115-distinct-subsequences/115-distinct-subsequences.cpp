class Solution {
public:
//     int f(int i,int j,string s,string t,vector<vector<int>>dp)
//     {
//         if(j<0)
//             return 1;
//         if(i<0)
//             return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         if(s[i]==t[j])
//             return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
//         else
//             return dp[i][j]=f(i-1,j,s,t,dp);
//     }
    
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long >> dp(s.length()+1,vector<unsigned long long>(t.length()+1,-1));
        // int ans=f(s.length()-1,t.length()-1,s,t,dp);
        // return ans;
        int n=s.length(),m=t.length();
        for(unsigned long long i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        for(unsigned long long i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(unsigned long long i=1;i<=n;i++)
        {
            for(unsigned long long j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][m];
        
    }
};