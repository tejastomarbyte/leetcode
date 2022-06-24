// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
typedef long long int ll;
const int mod=1e9+7;
class Solution {
  public:
    ll f(ll n,vector<ll>&dp)
    {
        if(n==0 || n==1)
         return 1;
         if(dp[n]!=-1)return dp[n];
         
        return dp[n]=(f(n-1,dp) * (f(n-1,dp)+2*f(n-2,dp))) % mod;
    }
    long long int countBT(int h) { 
        // code here
        vector<ll>dp(h+1,-1);
        
        dp[0]=1;
        dp[1]=1;
        if(h==1 || h==0)
        return 1;
        for(int i=2;i<=h;i++)
        {
            dp[i]=(dp[i-1]*(dp[i-1]+2*dp[i-2]))%mod;
        }
        
        return dp[h];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends