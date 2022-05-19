class Solution {
public:
    int dp[201][201];
    vector<int>dx={1,-1,0,0},dy={0,0,-1,1};
    int r,c;
    bool isvalid(int i,int j)
    {
        if(i>=0 && j>=0 && i<r && j<c)return true;
        return false;
    }
    int dfs(vector<vector<int>>&m,int i,int j)
    {
        if(i<0 || i>=m.size() || j<0 || j>m[0].size())
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int fin=0;
        for(int p=0;p<4;p++)
        {
            int ans=0;
            if(isvalid(i+dx[p],j+dy[p]) && m[i+dx[p]][j+dy[p]]>m[i][j])
                ans=1+dfs(m,i+dx[p],j+dy[p]);
            fin=max(fin,ans);
        }
        return dp[i][j]=fin;
         
    }
    int longestIncreasingPath(vector<vector<int>>& m) {
        int longest=0;
        r=m.size();
        c=m[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m.size();i++)
        {   vector<vector<bool>>vis(m.size(),vector<bool>(m[0].size(),false));
            for(int j=0;j<m[i].size();j++)
            {
                int ans=1+dfs(m,i,j);
                longest=max(longest,ans);
            }
        }
        return longest;
    }
};