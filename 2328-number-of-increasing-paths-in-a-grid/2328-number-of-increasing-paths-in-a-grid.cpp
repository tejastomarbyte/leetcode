class Solution {
public:
    int ans;
    const int mod=1e9+7;
    int n,m;
    vector<vector<int>>dp;
    bool isvalid(int i,int j)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }
    int f(vector<vector<int>>& grid,int i,int j)
    {
        
        int up=0,down=0,left=0,right=0,ans=1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(isvalid(i-1,j) && grid[i-1][j]>grid[i][j])
            ans=(ans+f(grid,i-1,j))%mod;
        
        if(isvalid(i+1,j) && grid[i+1][j]>grid[i][j])
            ans=(ans+f(grid,i+1,j))%mod;
        
        if(isvalid(i,j-1) && grid[i][j-1]>grid[i][j])
            ans=(ans+f(grid,i,j-1))%mod;
        
        if(isvalid(i,j+1) && grid[i][j+1]>grid[i][j])
            ans=(ans+f(grid,i,j+1))%mod;
        
        
        return dp[i][j]=ans%mod;
        
    }
        int countPaths(vector<vector<int>>& grid) {
        
        
        int ans=0;
        n=grid.size(),m=grid[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=(ans+f(grid,i,j))%mod;
            }
        }
        return ans;
    }
};