class Solution {
public:
//     bool isvalid(vector<vector<int>>g,int i,int j,vector<vector<bool>>&vis)
//     {
//         if(i>=0 && i<g.size() && j>=0 && j<g[0].size() && !vis[i][j] && g[i][j]==0)
//             return true;
//         return false;
//     }
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         // int ans=1;
//         vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
//         if(grid[0][0]==1)
//             return -1;
        
//         queue<pair<int,int>>q;
//         q.push({0,0});
//         vis[0][0]=true;
//         int n=grid.size(),m=grid[0].size();
//         int ans=0;
//         while(!q.empty())
//         {
//             int size=q.size();
//             ans++;
//             for(int tt=0;tt<size;tt++)
//             {
//                 pair<int,int>p=q.front();
//                 q.pop();
//                 int i=p.first;
//                 int j=p.second;
                
//                 if(i==n-1 && j==m-1)
//                     return ans;
                 
//                  for(int p=0;p<8;p++)
//                  {
//                       int ii=i+dir[p].first;
//                       int jj=j+dir[p].second;
//                       if(isvalid(grid,ii,jj,vis))
//                         {
//                             q.push({ii,jj});
//                             vis[ii][jj]=true;
//                         }
//                  }
                        
                    
                
//             }
            
//         }
//         return -1;
            
//     }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n= grid.size();
        vector<vector<int>>vis(n, vector<int>(n,0));
        
        if(grid[0][0]==1)return -1;
        
        queue<pair<int,int>>q;
        int step=1,ans=1e9;
        int dr[8][2]={{-1,-1},{-1,1},{1,-1},{1,1},{0,1},{0,-1},{1,0},{-1,0}};
        q.push({0,0});
        while(!q.empty()){
            int size= q.size();
            for(int i=0 ; i<size ; i++){
                int curi=q.front().first;
                int curj=q.front().second;
                if(curi==curj&& curi==n-1){
                    ans=min(ans,step);
                }
                q.pop();
                for(int k=0 ; k<8 ; k++){
                    
                    int x=curi+dr[k][0];
                    int y=curj+dr[k][1];
                    if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==0&& !vis[x][y]){
                        
                        vis[x][y]=1;
                        q.push({x,y});
                        
                    }
                    
                }
                
            }
            
            step++;
        }
        
        if(ans==1e9)return -1;
        return ans;
        
    }
};