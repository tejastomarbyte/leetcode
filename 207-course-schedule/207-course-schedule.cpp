class Solution {
public:
    vector<int> g[100005];
    bool canFinish(int num, vector<vector<int>>& prerequisites) {
        vector<int> v(num,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
            v[prerequisites[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<num;i++)
        {
            if(v[i]==0)
                q.push(i);
        }
        int count=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            for(auto it:g[node])
            {
                v[it]--;
                if(v[it]==0)
                    q.push(it);
            }
        }
        
        return (count==num);
                
    }
};