// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string a, string b, string c) 
    {
        //Your code here
        if(a.length()+b.length()!=c.length())
        return false;
        
        int n=a.length(),m=b.length();
        bool dp[n+1][m+1]={false};
        
        for(int i=0;i<=n;i++){
           for(int j=0;j<=m;j++){
               
               if(i==0 && j==0){
                   dp[i][j]=true;
                   continue;
               }
           
        
          bool temp1=false,temp2=false;
                if(i!=0 && c[i+j-1]==a[i-1])
                temp1=dp[i-1][j];
                if(j!=0 && c[i+j-1]==b[j-1])
                temp2=dp[i][j-1];
                
                dp[i][j]=temp1 or temp2;
                
           }
        }
            
        return dp[n][m];
        
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends