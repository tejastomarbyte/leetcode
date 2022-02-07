class Solution {
public:
    int path(vector<vector<int>> &a,int i,int j,vector<vector<int>> &dp)
    {   if(i>=0 && j>=0 && a[i][j]==1)return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int left=path(a,i,j-1,dp);
        int up=path(a,i-1,j,dp);
        return dp[i][j]=left+up;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return path(grid,n-1,m-1,dp);
    }
};