class Solution {
public:
    int f(vector<int>&s,int i,int j,vector<vector<int>>&dp,int sum)
    {
        if(i>=j)
            return 0;
        if(sum<=0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        int left=sum-s[i]-f(s,i+1,j,dp,sum-s[i]);
        int right=sum-s[j]-f(s,i,j-1,dp,sum-s[j]);
        
        return dp[i][j]=max(left,right);
    }
    int stoneGameVII(vector<int>& s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        int sum=0;
        for(auto i:s)
            sum+=i;
        return f(s,0,s.size()-1,dp,sum);
    }
};