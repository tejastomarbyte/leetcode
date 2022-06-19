// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends()
 class Solution
{
   
   public:
   int find(vector<vector<int>>&g,int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&dp)
   {
       if(i<0 || j<0 || i>=g.size() || j>=g[0].size()) return 1e5;
       
       if(vis[i][j]==true)
       {
           if(dp[i][j]!=-1) return dp[i][j];
           return 1e5;
       }
       if(g[i][j]==1) 
       {
           
           return dp[i][j]=0;
       }
       
       int mini=1e5;
       vis[i][j]=true;
       int up=1+find(g,i-1,j,vis,dp);
       int down=1+find(g,i+1,j,vis,dp);
       int left=1+find(g,i,j-1,vis,dp);
       int right=1+find(g,i,j+1,vis,dp);
       
       
       return dp[i][j]=min({left,right,up,down});
       
   }
   vector<vector<int>> nearest(vector<vector<int>>&g)
   {
       // Code here
       
       int n=g.size();
       int m=g[0].size();
       vector<vector<int>> ans(n,vector<int>(m,0));
       vector<vector<int>> dp(n,vector<int>(m,-1));
       vector<vector<bool>>vis(n,vector<bool>(m,false));
       
      
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(g[i][j]==0)
               {
                   vis[i][j]=false;
                   int val=find(g,i,j,vis,dp);
                   ans[i][j]=val;
               }
           }
       }
       return ans;
       
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends