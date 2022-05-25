// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int a[], int n) {
        
        
        // code here
        //if n==0 or first element is 0
        if(n==0 || a[0]==0)
        return INT_MAX;
        
        //dp[i] is the minimum no. of steps from 0 ... i
        vector<int>dp(n);
        dp[0]=0; //no. of steps to reach 1st index from 1st index
        
        for(int i=1;i<n;i++)
        {   dp[i]=INT_MAX;
            for(int j=0;j<i;j++)
            {
                if(j+a[j]>=i && dp[j]!=INT_MAX)//if we can reach ith index from jth index in a better way than the current
                {
                    dp[i]=min(dp[j]+1,dp[i]);
                    break; //because j moves from 0..i-1 and the first time it enters the if block
                           //it will give the best answer
                }
            }
        }
        if(dp[n-1]!=INT_MAX)return 1;
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends