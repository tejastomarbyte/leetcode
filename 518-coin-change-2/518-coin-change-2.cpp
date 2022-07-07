class Solution {
public:
    int f(int am,vector<int>& c,int i,vector<vector<int>>&dp)
    {
        if(am==0)
            return 1;
        
        if(i==c.size())
        {
            if(am==0)
                return 1;
            return 0;
        }
        if(dp[i][am]!=-1)return dp[i][am];
        
        int take=0,nottake=0;
        
        if(c[i]<=am)
            take=f(am-c[i],c,i,dp);
        nottake=f(am,c,i+1,dp);
        return dp[i][am]=take+nottake;
        
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end());
        return f(amount,coins,0,dp);
    }
};