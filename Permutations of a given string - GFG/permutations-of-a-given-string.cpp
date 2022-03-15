// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	    void permute(vector<string> &ans,string s,int l,int r)
	    {
	        if(l==r)
	        {
	            ans.push_back(s);
	        }
	        else
	        {
	            for(int i=l;i<=r;i++)
	            {
	                
	                swap(s[l],s[i]);
	                
	                permute(ans,s,l+1,r);
	                swap(s[l],s[i]);
	            }
	        }
	          
	    }
		vector<string> find_permutation(string s)
		{
		    // Code here there
		    vector<string> ans;
		    permute(ans,s,0,s.length()-1);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends