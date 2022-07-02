class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        
        q.push(start);
        vector<bool>vis(arr.size(),false);
        vis[start]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            vis[node]=true;
            if(arr[node]==0)
                return true;
            
            if(node+arr[node]<arr.size() && vis[node+arr[node]]==false)
                q.push(node+arr[node]);
            if(node-arr[node]>=0 && vis[node-arr[node]]==false)
                q.push(node-arr[node]);
        }
        return false;
        
    }
};