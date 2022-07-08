// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  const int mod=1e9+7;
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    vector<int>dp(s.length()+1);
	    dp[0]=1;
	    unordered_map<char,int>m;
	    for(int i=1;i<dp.size();i++)
	    {
	        dp[i]=(dp[i-1]*2)%mod;
	        if(m.find(s[i-1])!=m.end())
	        {
	            int temp=m[s[i-1]];
	            dp[i]=(dp[i]-dp[temp-1]+mod)%mod;
	        }
	        m[s[i-1]]=i;
	        
	    }
	    return dp[s.length()]%mod;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends