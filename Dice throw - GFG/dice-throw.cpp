// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long f(int m,int n,int x,vector<vector<long long>>&dp)
    {
        
        if(n==0)
        {
            if(x==0)return 1;
            return 0;
        }
        if(dp[n][x]!=-1)return dp[n][x];
        long long count=0;
        
        for(int i=1;i<=m;i++)
        {
            if(i<=x)
            count+=f(m,n-1,x-i,dp);
            
        }
        
        
        return dp[n][x]=count;
    }
    long long noOfWays(int m , int n , int x) {
        // code here
        vector<vector<long long>>dp(n+1,vector<long long>(x+1,-1));
        long long ans=f(m,n,x,dp);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}  // } Driver Code Ends