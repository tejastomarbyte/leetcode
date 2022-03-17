// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     void bfs(vector<bool>&vis,vector<vector<int>>adj,int ind)
    {
        queue<int>q;
        q.push(ind);
        vis[ind]=true;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(int i=0;i<adj[t].size();i++)
            {
                if(vis[i]==false && adj[t][i]==1)
                {
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int v) {
        // code here
        int ans=0;
        vector<bool> vis(v,false);
        int ind=0;
        for(int i=0;i<v;i++)
        {   if(!vis[i])
            {
                    ans++;
                    bfs(vis,adj,i);
            } 
            
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends