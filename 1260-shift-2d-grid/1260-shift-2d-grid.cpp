class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size(),t=grid[n-1][m-1];
        for(int p=0;p<k;p++)
        {   t=grid[n-1][m-1];
            for(int i=n-1;i>=0;i--)
            {
                for(int j=m-1;j>=0;j--)
                {
                    if(i==0 && j==0)
                        grid[i][j]=t;
                    else if(j==0)
                    {
                        grid[i][j]=grid[i-1][m-1];
                    }
                    else 
                    {
                        grid[i][j]=grid[i][j-1];
                    }

                }
            }
        }
        return grid;
    }
};