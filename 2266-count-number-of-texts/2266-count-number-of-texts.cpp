const int mod=1e9+7;
class Solution {
public:
    // int f(string p,int i,int n,vector<int>&dp)
    // {
    //     if(i>=n)return 1;
    //     if(dp[i]!=-1)return dp[i];
    //     int ans=0;
    //     if(i+1<n && p[i]==p[i+1])
    //     {
    //         ans+=f(p,i+2,n,dp);
    //         ans=(ans)%mod;
    //         if(i+2<n && p[i]==p[i+2])
    //         {
    //             ans+=f(p,i+3,n,dp);
    //             ans=(ans)%mod;
    //             if(i+3<n && p[i]==p[i+3] && (p[i]=='7' || p[i]=='9'))
    //             {
    //                 ans+=f(p,i+4,n,dp);
    //                 ans=(ans)%mod;
    //             }
    //         }
    //     }
    //     ans+=f(p,i+1,n,dp);
    //     ans=ans%mod;
    //     return dp[i]=ans;
    // }
    int countTexts(string p) {
        int n=p.length();
        vector<int>dp(p.length()+1,0);
        dp[p.length()]=1;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
           if(i+1<n && p[i]==p[i+1])
            {
                dp[i]+=dp[i+2];
                dp[i]=dp[i]%mod;
                if(i+2<n && p[i]==p[i+2])
                {
                    dp[i]+=dp[i+3];
                    dp[i]=(dp[i])%mod;
                    if(i+3<n && p[i]==p[i+3] && (p[i]=='7' || p[i]=='9'))
                    {
                        dp[i]+=dp[i+4];
                        dp[i]=(dp[i])%mod;
                    }
                }
            }
            dp[i]+=dp[i+1];
            dp[i]=dp[i]%mod;
        }
        
        
        return dp[0];
    }
};