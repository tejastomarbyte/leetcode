// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int r,int c,int n,vector<vector<int>> m,vector<vector<int>> &dp)
    {
        if(r<0 || r>n || c<0 || c>n)
        return 0;
        if(r==n)
        {
            return m[n][c];
        }
        if(dp[r][c]!=-1)return dp[r][c];
        int left=m[r][c]+f(r+1,c,n,m,dp);
        int diag=m[r][c]+f(r+1,c-1,n,m,dp);
        int down=m[r][c]+f(r+1,c+1,n,m,dp);
        
        return dp[r][c]=max(left,max(diag,down));
        
    }
    int maximumPath(int n, vector<vector<int>> m)
    {
        // code here
        int ans=INT_MIN;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++)
        dp[n-1][i]=m[n-1][i];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {   
                
                int left=INT_MIN;
                int diag=INT_MIN;
                int down=INT_MIN;
                
                if(i+1<=n-1)
                left=m[i][j]+dp[i+1][j];
                if(i+1<=n-1 && j+1<=n-1)
                diag=m[i][j]+dp[i+1][j+1];
                if(i+1<=n-1 && j-1>=0)
                down=m[i][j]+dp[i+1][j-1];
                
                dp[i][j]=max(left,max(down,diag));
            }
        }
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[0][i]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends