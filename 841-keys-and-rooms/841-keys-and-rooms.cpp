class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>vis(rooms.size(),false);
        vector<int>adj[rooms.size()];
        for(int i=0;i<rooms.size();i++)
        {
            for(int j=0;j<rooms[i].size();j++)
                adj[i].push_back(rooms[i][j]);
            
        }
        int n=rooms.size();
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(vis[it]==false)
                {
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
        // int ans=true;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<vis[i]<<" ";
        // }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                return false;
        }
        return true;
        
    }
};