class Solution {
public:
    vector<int>dp;
    bool isP(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++,j--;
        }
        return true;
    }
    
    int f(string &s,int i)
    {
        if(i==s.length())
            return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        
        for(int idx=i;idx<s.length();idx++)
        {
            if(isP(s,i,idx))
            {
                ans=min(ans,1+f(s,idx+1));
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
       
        dp.resize(s.length()+1,0);
        
        for(int i=s.length()-1;i>=0;i--)
        {
            int ans=INT_MAX;

            for(int idx=i;idx<s.length();idx++)
            {
                if(isP(s,i,idx))
                {
                    ans=min(ans,1+dp[idx+1]);
                }
            }
            dp[i]=ans;
        }
        return dp[0]-1;
        
    }
};