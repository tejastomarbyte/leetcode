class Solution {
public:
    int dfs(vector<vector<int>>&m,int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&dp)
    {
        if(i<0 || i>=m.size() || j<0 || j>m[0].size())
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        vis[i][j]=true;
        
        int left=0,right=0,up=0,down=0;
        
        if(j-1>=0 && m[i][j-1]>m[i][j])
            left=1+dfs(m,i,j-1,vis,dp);
        if(j+1<m[0].size() && m[i][j+1]>m[i][j])
            right=1+dfs(m,i,j+1,vis,dp);
        if(i-1>=0 && m[i-1][j]>m[i][j])
            up=1+dfs(m,i-1,j,vis,dp);
        if(i+1<m.size() && m[i+1][j]>m[i][j])
            down=1+dfs(m,i+1,j,vis,dp);
        
        return dp[i][j]=max(max(left,right),max(up,down));
         
    }
    int longestIncreasingPath(vector<vector<int>>& m) {
        int longest=0;
        vector<vector<int>>dp(m.size(),vector<int>(m[0].size(),-1));
        for(int i=0;i<m.size();i++)
        {   vector<vector<bool>>vis(m.size(),vector<bool>(m[0].size(),false));

            for(int j=0;j<m[i].size();j++)
            {
                int ans=1+dfs(m,i,j,vis,dp);
                longest=max(longest,ans);
            }
        }
        return longest;
    }
};