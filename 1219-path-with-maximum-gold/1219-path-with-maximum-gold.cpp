class Solution {
public:
    int f(vector<vector<int>>&grid,int i,int j)
    {
        if(i<0 || i>grid.size()-1 || j<0 || j>grid[0].size()-1 || grid[i][j]<=0)
            return 0;
        grid[i][j]=-grid[i][j];
        
        
        int left=f(grid,i,j-1);
        int right=f(grid,i,j+1);
        int up=f(grid,i+1,j);
        int down=f(grid,i-1,j);
        grid[i][j]=-grid[i][j];
        return grid[i][j]+max({left,right,up,down});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int maxi=INT_MIN;
        
        for(int i=0;i<grid.size();i++)
        {   
            for(int j=0;j<grid[0].size();j++)
            {
                
                int ans=f(grid,i,j);
                maxi=max(maxi,ans);
            }
        }
        
        return maxi;
    }
};