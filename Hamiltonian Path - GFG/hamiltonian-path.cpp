// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    bool *vis;
    vector<int> *adj;
    bool dfs(int i,int total,int n)
    {
        vis[i]=true;
        
        if(total==n)
        return true;
        
        for(auto it:adj[i])
        {
            if(!vis[it] && dfs(it,total+1,n))
            return true;
        }
        vis[i]=false;
        return false;
    }
    
    bool check(int n,int m,vector<vector<int>> e)
    {
        
        // code here
        vis=new bool[n+1];
        adj=new vector<int>[n+1];
        
        for(int i=0;i<e.size();i++)
        {
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        
        for(int i=1;i<=n;i++)
        {
            if(dfs(i,1,n))
            return true;
        }
        return false;
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends