class Solution {
public:
    int findCircleNum(vector<vector<int>>& is) {
        int n=is.size();
        vector<int>adj[n+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(is[i][j] && i!=j)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                    is[i][j] = 0;
                    is[j][i] = 0;
                }
            }
        }
        // for(int i=1;i<=n;i++)
        // {
        //     for(auto it:adj[i])
        //         cout<<it<<" ";
        //     cout<<endl;
        // }
        int count=0;
        vector<bool>vis(n+1,false);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false)
            {
                count++;
                // cout<<i<<" ";
                vis[i]=true;
                queue<int>q;
                q.push(i);
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    // vis[node]=true;
                    for(auto it:adj[node])
                    {
                        if(vis[it]==false)
                        {
                            vis[it]=true;
                            q.push(it);
                        }
                    }
                }
                
            }
        }
        return count;
    }
};