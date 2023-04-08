//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,
    vector<pair<int,int>>&vec,int row0,int col0,int i,int j)
    {
        vis[i][j]=1;
        vec.push_back({i-row0,j-col0});
        
        vector<int>dx={-1,0,0,1},dy={0,-1,1,0};
        
        for(int ii=0;ii<4;ii++)
        {
            int x=i+dx[ii],y=j+dy[ii];
            if(x>=0 and y>=0 and x<grid.size() and y<grid[0].size()
            and grid[x][y]==1 and !vis[x][y])
            dfs(grid,vis,vec,row0,col0,x,y);
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),0));
        
        set<vector<pair<int,int>>>st;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vector<pair<int,int>>vec;
                if(grid[i][j] and !vis[i][j])
                {
                    dfs(grid,vis,vec,i,j,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends