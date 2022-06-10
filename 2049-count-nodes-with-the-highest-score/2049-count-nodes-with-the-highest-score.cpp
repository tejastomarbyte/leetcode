typedef long long int ll;

class Solution {
public:
    void dfs(vector<ll>&dp,vector<ll>adj[],ll src,ll par)
    {
        dp[src]=1;
        
        for(auto it:adj[src])
        {
            if(it!=par)
            {
                dfs(dp,adj,it,src);
                dp[src]+=dp[it];
            }
        }
    }
    int countHighestScoreNodes(vector<int>& p) {
        int n=p.size();
        vector<ll>adj[n];
        vector<ll>dp(n,0);
        for(ll i=1;i<n;i++)
        {
            adj[p[i]].push_back(i);
        }
        
        dfs(dp,adj,0,-1);
        map<ll,ll>m;
        for(ll i=0;i<n;i++)
        {
            if(adj[i].size()==0)
            {
                  m[n-1]++;
            }
            else if(adj[i].size()==1)
            {
               ll left = dp[adj[i][0]];
                ll right = 1;
                ll rem = n-1-left;
                if(rem==0)
                    rem=1;
              m[left*right*rem]++;  
            }
            else
            {
                 ll left = dp[adj[i][0]];
                 ll right = dp[adj[i][1]];
                 ll rem = n-1-left-right;
                 if(rem==0)
                     rem=1;
                m[left*right*rem]++;
            }
        }
        return m.rbegin()->second;
        
    }
};