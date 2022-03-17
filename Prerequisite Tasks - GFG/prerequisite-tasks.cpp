// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& preq) {
	    // Code here
	    vector<int> adj[n];
	    vector<int>indegree(n,0);
	    for(auto it:preq)
	    {
	        adj[it.second].push_back(it.first);
	        indegree[it.first]++;
	   }
	   queue<int>q;
	   int count=0;
	   for(int i=0;i<n;i++)
	   {
	       if(indegree[i]==0)
	       q.push(i);
	   }
	   
	   while(!q.empty())
	   {
	       int t=q.front();
	       q.pop();
	       count++;
	       for(auto it:adj[t])
	       {
	           indegree[it]--;
	           if(indegree[it]==0)
	            q.push(it);
	       }
	   }
	   return (count==n)?true:false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends