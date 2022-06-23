class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>indeg(n,0);
        
        vector<int>adj[n];
        
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
            indeg[pre[i][1]]++;
        }
        
        
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        
        vector<int>topo1,topo2;
        int count=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo1.push_back(node);
            count++;
            for(auto it:adj[node])
            {
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        
        if(count!=n)
            return topo2;
        
        for(int i=0;i<n/2;i++)
        {
            int t=topo1[i];
            topo1[i]=topo1[n-i-1];
            topo1[n-i-1]=t;
        }
        
        return topo1;
        
    }
};