class Solution {
public:
    
    void dfs(vector<vector<int>> &ans,vector<int> t,vector<vector<int>>graph,int ind)
    {
        if(ind==graph.size()-1)
        {
            ans.push_back(t);
            return;
        }
        
        for(auto it:graph[ind])
        {
            t.push_back(it);
            dfs(ans,t,graph,it);
            t.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> t;
        t.push_back(0);
        dfs(ans,t,graph,0);
        return ans;
    }
};