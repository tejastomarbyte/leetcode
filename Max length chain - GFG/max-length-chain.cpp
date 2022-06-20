// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(p,p+n,[](val a, val b){
        return a.second<b.second;
    });
    
    vector<int>dp(n,1);
    for(int i=1;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(p[prev].second<p[i].first)
            {
                dp[i]=max(dp[i],1+dp[prev]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
    
    
}