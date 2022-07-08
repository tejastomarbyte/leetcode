class Solution {
public:
    vector<pair<int,int>>d={{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(vector<vector<int>>&grid,int i,int j)
    {
        if(i<0 or j<0 or i>grid.size()-1 or j>grid[0].size()-1 or grid[i][j]==0)
            return 0;
        
        int ans=1;
        grid[i][j]=0;
        for(int k=0;k<4;k++)
        {
            ans+=dfs(grid,i+d[k].first,j+d[k].second);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};