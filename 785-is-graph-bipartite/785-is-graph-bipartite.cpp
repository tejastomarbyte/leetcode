class Solution {
public:
    
    bool g(vector<vector<int>> &graph,int src,vector<int> &col)
    {
        queue<int> q;
        q.push(src);
        col[src]=1;
        
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            
            for(auto it:graph[t])
            {
                if(col[it]==-1)
                {
                    col[it]=1-col[t];
                    q.push(it);
                }
                else if(col[it]==col[t])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col(graph.size(),-1);
        for(int i=0;i<col.size();i++)
        {
            if(col[i]==-1)
            {
                if(g(graph,i,col)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};