class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        if(grid[0][0]==1 or grid[n-1][n-1]==1)
            return -1;
        vis[0][0]=true;
        q.push({0,0});
        int dist=1;
        vector<pair<int,int>> d={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int a=q.front().first,b=q.front().second;
                q.pop();
                
                if(a==grid.size()-1 && b==grid[0].size()-1)
                    return dist;
                
                for(int i=0;i<8;i++)
                {
                    int x1=a+d[i].first,y1=b+d[i].second;
                    if(x1>=0 && y1>=0 && x1<grid.size() && y1<grid.size() && vis[x1][y1]==false && grid[x1][y1]==0)
                    {
                        vis[x1][y1]=true;
                        q.push({x1,y1});
                    }
                }
            }
            dist++;
            
        }
        return -1;
    }
};