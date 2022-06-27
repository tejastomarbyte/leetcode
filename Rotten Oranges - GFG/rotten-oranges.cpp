// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool isvalid(int i,int j,int n,int m)
    {
        return (i<n && j<m && i>=0 && j>=0);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==2)
                q.push({i,j});
                
        vector<int>dx={1,0,0,-1},dy={0,1,-1,0};
        int count=0;
        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                auto p=q.front();
                q.pop();
                int a=p.first,b=p.second;
                for(int j=0;j<4;j++)
                {
                    if(isvalid(a+dx[j],b+dy[j],n,m) && grid[a+dx[j]][b+dy[j]]==1)
                    {
                        q.push({a+dx[j],b+dy[j]});
                        grid[a+dx[j]][b+dy[j]]=2;
                    }
                }
                
            }
            if(q.size())
            count++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            if(grid[i][j]==1)return -1;
        }
        return count;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends