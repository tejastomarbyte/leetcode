// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
        int ans=0;
        for(int i=1;i<=s1.length();i++)
        {
           for(int j=1;j<=s2.length();j++)
           {
               if(s1[i-1]==s2[j-1])
               {
                   dp[i][j]=1+dp[i-1][j-1];
                   ans=max(ans,dp[i][j]);
               }
               else
               dp[i][j]=0;
           }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends