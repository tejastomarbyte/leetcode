// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> ma)
    {
        // code here
        
        vector<vector<int>>dp(n,vector<int>(n));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    dp[i][j]=ma[i][j];
                }
                else 
                {
                    
                    int left=INT_MIN,down=INT_MIN,right=INT_MIN;
                    if(j-1>=0)
                    left=dp[i-1][j-1];
                    down=dp[i-1][j];
                    if(j+1<n)
                    {
                        right=dp[i-1][j+1];
                    }
                    
                    dp[i][j]=ma[i][j]+max({left,down,right});
                }
            }
        }
        return *max_element(dp[n-1].begin(),dp[n-1].end());
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