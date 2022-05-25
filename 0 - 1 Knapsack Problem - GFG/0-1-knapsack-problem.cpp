// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int w,int wt[],int val[],int n,int i,vector<vector<int>>&dp)
    {
        if(i==n)
        return 0;
        if(w==0)
        return 0;
        if(dp[i][w]!=-1)return dp[i][w];
        int profit=0;
        if(wt[i]<=w)
        {
            profit=max(val[i]+f(w-wt[i],wt,val,n,i+1,dp),f(w,wt,val,n,i+1,dp));
        }
        else
            profit=f(w,wt,val,n,i+1,dp);
            
        return dp[i][w]=profit;    
    }
    
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
       int ans=f(w,wt,val,n,0,dp);
       return ans;
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends