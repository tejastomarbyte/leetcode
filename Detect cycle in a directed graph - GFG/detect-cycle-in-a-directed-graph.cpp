// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    // bool isf(int i,vector<int> dfs,vector<int> visdfs,vector<int> adj[])
    // {
    //     dfs[i]=1;
    //     visdfs[i]=1;
    //     for(auto it:adj[i])
    //     {
    //         if(dfs[it]==-1)
    //         {
    //             if(isf(it,dfs,visdfs,adj))return true;
    //         }
    //         else if(visdfs[it])  // if the element has been visited in the same dfs call
    //         {
    //             return true;
    //         }
    //     }
    //     visdfs[i]=0;
    //     return false;
        
    // }
    
    
    // bool isCyclic(int v, vector<int> adj[]) {
    //     // code here
        
    //     vector<int> dfs(v,-1),visdfs(v,-1);
    //     for(int i=0;i<v;i++)
    //     {   if(dfs[i]==-1)
    //         if(isf(i,dfs,visdfs,adj))return true;
    //     }
    //     return false;
    // }
    bool iscycle(vector<int> adj[], vector<bool> &visited, int i, vector<bool> &stack)
{
    stack[i] = true;
    if(!visited[i])
    {
        visited[i] = true;
        for(auto it : adj[i])
        {
            if(!visited[it] && iscycle(adj, visited, it, stack))
            return true;
            if(stack[it])
            return true;
        }
    }
    stack[i] = false;
    return false;
}
    bool isCyclic(int n, vector<int> adj[]) {
      
    vector<bool> visited(n, 0);
    vector<bool> stack(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && iscycle(adj, visited, i, stack))
            return true;
    }
    return false;
    }

};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends