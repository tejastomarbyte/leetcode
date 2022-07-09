class Solution {
public:
     vector<pair<int,int>>d={{0,1},{0,-1},{1,0},{-1,0}};
    
    void dfs(vector<vector<int>>&grid,int row,int col,int clr)
    {
        grid[row][col]=-clr;
        int count=0;
        for(int i=0;i<4;i++)
        {
            int r=row+d[i].first,c=col+d[i].second;
            if(r<0 or c<0 or r>grid.size()-1 or c>grid[0].size()-1 or abs(grid[r][c])!=clr)
                continue;
            
            count++;
            
            if(grid[r][c]==clr)
            {
                dfs(grid,r,c,clr);
            }
        }
        
        if(count==4)
            grid[row][col]=clr;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        dfs(grid,row,col,grid[row][col]);
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]<0)
                    grid[i][j]=color;
            }
        }
        return grid;
    }
    
   
};