class Solution {
public:
    //BFS check
    // bool bipartite(int i,vector<vector<int>> &graph,vector<int> &color)
    // {
    //     queue<int> q;
    //     q.push(i);
    //     color[i]=1;
    //     while(!q.empty())
    //     {
    //         int f=q.front();
    //         q.pop();
    //         for(auto it:graph[f])
    //         {
    //             if(color[it]==-1)
    //             {   color[it]=1-color[f];
    //                 q.push(it); 
    //             }
    //             else if(color[it]==color[i])
    //                 return false;
    //         }
    //     }
    //     return true;
    // }
     bool bipartite(int node , vector<vector<int>>& graph, vector <int> &color ){
        color[node] = 0;
        
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            
            for(auto it : graph[currNode]){
                if(color[it] == -1){
                    color[it] = 1 - color[currNode];
                    q.push(it);
                }
                else if(color[it] == color[currNode]) return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                if(!bipartite(i,graph,color))
                    return false;
            }
        }
        return true;
    }
};