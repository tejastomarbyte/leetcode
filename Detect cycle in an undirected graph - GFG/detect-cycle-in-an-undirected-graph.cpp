// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool f(int i,vector<int> adj[],int parent,vector<bool>&vis)
    {
        vis[i]=true;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
               if(f(it,adj,i,vis))
                 return true;
            }
            else if(it!=parent)
              return true;
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool>vis(v+1,false);
        
        
        for(int i=0;i<v;i++)
        {
            if(vis[i]==false)
            {
                if(f(i,adj,-1,vis))
                  return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends