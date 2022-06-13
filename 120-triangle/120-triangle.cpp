class Solution {
public:
    int f(vector<vector<int>>&t,int i,int j,vector<vector<int>>&dp)
    {
        if(i==t.size())
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans1=f(t,i+1,j,dp),ans2=f(t,i+1,j+1,dp);
        
        return dp[i][j]=t[i][j]+min(ans1,ans2);
    }
    int minimumTotal(vector<vector<int>>& tr) {
        vector<vector<int>>dp(tr.size()+1,vector<int>(tr.size()+1,-1));
        return f(tr,0,0,dp);
    }
};