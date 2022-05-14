class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push({0,k});
        
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        while(!pq.empty())
        {
            int d=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            vector<pair<int,int>>::iterator it;
            for(it=adj[prev].begin();it!=adj[prev].end();it++)
            {
                int next=it->first;
                int distnext=it->second;
                if(dist[next]>dist[prev]+distnext)
                {
                    dist[next]=dist[prev]+distnext;
                    pq.push({dist[next],next});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};