// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public: 
    vector<vector<int>>dp;
    
    int f(string &s1,string &s2,int i,int j)
    {
        if(j==s2.length())
            return 1;
        if(i>s1.length()-1)
        {
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])
        {
            dp[i][j]=f(s1,s2,i+1,j+1)+f(s1,s2,i+1,j);
        }
        else
            dp[i][j]=f(s1,s2,i+1,j);
        return dp[i][j];
    }
    
    int countWays(string S1, string S2){
        // code here
        dp.resize(S1.length()+1,vector<int>(S2.length()+1,-1));
        return f(S1,S2,0,0);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends