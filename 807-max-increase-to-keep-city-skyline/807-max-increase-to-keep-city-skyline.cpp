class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>row(n);
        vector<int>col(n);
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                row[i]=max(row[i],grid[i][j]);
                col[j]=max(col[j],grid[i][j]);
            }
        }
        
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                sum+=(min(row[i],col[j])-grid[i][j]);
        }
        
        return sum;
    }
};