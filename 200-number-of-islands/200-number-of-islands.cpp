class Solution {
public:
    void f(vector<vector<char>>& g,int i,int j)
    {
        if(i>=g.size()|| i<0 || j<0|| j>=g[0].size()|| g[i][j]!='1')
            return;
        
        g[i][j]='2';
        f(g,i+1,j);
        f(g,i-1,j);
        f(g,i,j+1);
        f(g,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        if(grid.size()==0)return 0;
        if(grid.size()==1 && grid[0].size()==1)
        {
            return grid[0][0]-'0';
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)   
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    f(grid,i,j);
                }
            }
        }
        return ans;
    }
};