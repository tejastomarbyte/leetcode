class Solution {
public:
    int f(string s,int i,vector<int> &dp)
    {
        if(i==s.length()-1)return (s[i] > '0') ? 1 : 0 ;
        if(i>=s.length())
            return 1;
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];
        
        int l=f(s,i+1,dp);
        
        string t;
        t+=s[i];
        t+=s[i+1];
        int r=0;
        if(t<="26")
        {
            r=f(s,i+2,dp);
        }
        return dp[i]=l+r;
    }
    int numDecodings(string s) {

        vector<int>dp(s.length(),-1);
        int ans=f(s,0,dp);
        return ans;
    }
};