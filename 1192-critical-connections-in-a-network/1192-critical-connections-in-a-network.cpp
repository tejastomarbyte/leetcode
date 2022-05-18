class Solution {
// public:
//     void dfs(int i,int parent,int &timer,vector<int>&adj[],vector<bool>&vis,vector<int>&tin,vector<int>&low,vector<vector<int>>&ans)
//     {
//          vis[i]=true;
//          tin[i]=low[i]=timer++;
//          for(auto it:adj[i])
//          {
//              if(it==parent)
//                  continue;
//              if(!vis[it])
//              {
//                  dfs(it,i,timer,adj,vis,tin,low,ans);
//                  low[i]=min(low[it],low[i]);
//                  if(low[it]>tin[i])
//                  {
//                      ans.push_back({i,it});
//                  }
//              }
//              else
//              {
//                  low[i]=min(low[i],tin[it]);
//              }
//          }

//     }
//     vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
//         vector<int>adj[c.size()];
//         // int n=c.size();
//         for(int i=0;i<c.size();i++)
//             adj[c[i][0]].push_back(c[i][1]);
//         vector<bool>vis(n,false);
//         vector<int>tin(n,-1);
//         vector<int>low(n,-1);
//         vector<vector<int>>ans;
//         int timer=0;
//         for(int i=0;i<n;i++)
//         {
//             if(!vis[i])
//                 dfs(i,-1,timer,adj,vis,tin,low,ans);
//         }
//         return ans;
//     }
    public:
    vector<int> disc{0}, low{0};
    int time = 1;
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> edgeMap;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        disc = vector<int>(n);
        low = vector<int>(n);
        for (auto conn : connections) {
            edgeMap[conn[0]].push_back(conn[1]);
            edgeMap[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1);
        return ans;
    }
    void dfs(int curr, int prev) {
        disc[curr] = low[curr] = time++;
        for (int next : edgeMap[curr]) {
            if (disc[next] == 0) {
                dfs(next, curr);
                low[curr] = min(low[curr], low[next]);
            } else if (next != prev)
                low[curr] = min(low[curr], disc[next]);
            if (low[next] > disc[curr]) 
                ans.push_back({curr, next});
        }
    }

};