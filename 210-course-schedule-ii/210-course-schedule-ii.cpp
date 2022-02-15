class Solution {
public:
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        queue<int>q;
        vector<int> g[n];
        vector<int>v(n,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
            v[prerequisites[i][1]]++;
        }
        for(int i=0;i<n;i++)if(v[i]==0)q.push(i);
        int count=0;
        vector<int>topo;
        vector<int>topo1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            topo.push_back(node);
            for(auto it:g[node])
            {
                v[it]--;
                if(v[it]==0)
                    q.push(it);
            }
        }
        if(count!=n)
            return topo1;
        
        for(int i=0;i<topo.size()/2;i++)
        {
            int c=topo[i];
            topo[i]=topo[topo.size()-i-1];
            topo[topo.size()-i-1]=c;
        }
        return topo;
    }
};