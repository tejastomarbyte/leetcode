class Solution {
public:
    int minimumTotal(vector<vector<int>>& tr) {
        vector<vector<int>>dp(tr.size()+1,vector<int>(tr.size()+1,-1));
        for(int i=0;i<tr.size();i++)
        {
            dp[tr.size()-1][i]=tr[tr.size()-1][i];
        }
        int n=tr.size();
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i][j]=tr[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
            
        }
        return dp[0][0];
    }
};