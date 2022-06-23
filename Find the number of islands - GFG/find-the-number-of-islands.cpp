// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<int>dx{0,0,1,1,-1,-1,1,-1},dy{-1,1,-1,1,-1,1,0,0};
    void dfs(vector<vector<char>>&grid,vector<vector<bool>>&vis,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0' || vis[i][j])
        return;
        
        vis[i][j]=true;
        
        dfs(grid,vis,i,j+1);
        dfs(grid,vis,i,j-1);
        dfs(grid,vis,i+1,j);
        dfs(grid,vis,i-1,j);
        dfs(grid,vis,i-1,j-1);
        dfs(grid,vis,i-1,j+1);
        dfs(grid,vis,i+1,j+1);
        dfs(grid,vis,i+1,j-1);
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
            
        }
        return count;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends