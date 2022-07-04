// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    vector<pair<int,int>>dx={{0,1},{0,-1},{1,1},{-1,1},{-1,0},{1,0},{-1,-1},{1,-1}};
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1 || !grid[i][j])
        return 0;
        
        int sum=0;
        
        grid[i][j]=0;
        
        for(int k=0;k<8;k++)
        {
            sum+=dfs(grid,i+dx[k].first,j+dx[k].second);
        }
        return 1+sum;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),maxi=0;
        for(int i=0;i<n;i++)
        {   
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                 {
                     maxi=max(maxi,dfs(grid,i,j));
                 }
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends