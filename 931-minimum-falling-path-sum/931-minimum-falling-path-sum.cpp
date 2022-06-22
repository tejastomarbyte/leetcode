class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& ma) {
        vector<vector<int>>dp(ma.size(),vector<int>(ma[0].size(),-1));
        
        int ans=INT_MAX;
        
        for(int i=0;i<ma.size();i++)
        {
            for(int j=0;j<ma[0].size();j++)
            {
                if(i==0)
                    dp[i][j]=ma[i][j];
                
                else
                {
                    int left=INT_MAX,right=INT_MAX,down;
                    if(j>=1)
                        left=dp[i-1][j-1];
                    down=dp[i-1][j];
                    if(j<ma[0].size()-1)
                        right=dp[i-1][j+1];
                    dp[i][j]=ma[i][j]+min({left,right,down});
                }
            }
        }
        int n=ma.size();
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};