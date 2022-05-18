const int mod=1e9+7;
class Solution {
public:
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