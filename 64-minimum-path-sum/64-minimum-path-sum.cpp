class Solution {
public:
    // int dp[201][201]={-1}
//     int path(vector<vector<int>> a,int n,int m,int i,int j)
//     {   if(i>=n || j>=m || i<0 || j<0)
//          return INT_MAX;
//         if(i==n-1 && j==m-1)
//             return a[i][j];
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         else
//         return dp[i][j]=a[i][j]+min(path(a,n,m,i+1,j),path(a,n,m,i,j+1));
        
//     }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int dp[n][m];
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-2;i>=0;i--)
        {
            dp[i][m-1]=grid[i][m-1]+dp[i+1][m-1];
        }
        for(int j=m-2;j>=0;j--)
        {
            dp[n-1][j]=grid[n-1][j]+dp[n-1][j+1];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
