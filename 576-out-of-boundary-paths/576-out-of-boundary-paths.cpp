class Solution {
public:
    vector<pair<int,int>> d={{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<bool>>vis;
    int dp[52][52][52];
    const int mod=1e9+7;
    int f(int r,int c,int moves,int m,int n)
    {
        if((r<0 or c<0 or r>=m or c>=n))
            return 1;
        
        if(moves<=0)
            return 0;
        if(dp[r][c][moves]!=-1)return dp[r][c][moves];
        int ans=0;
        vis[r][c]=true;
        for(int i=0;i<4;i++)
        {
            
                ans=(ans%mod+f(r+d[i].first,c+d[i].second,moves-1,m,n)%mod)%mod;
        }
        
        return dp[r][c][moves]=ans;
    }
    int findPaths(int m, int n, int maxMove, int r, int c) {
        vis.resize(m,vector<bool>(n,false));
        memset(dp,-1,sizeof(dp));
        return f(r,c,maxMove,m,n);
    }
};