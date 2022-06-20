// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void f(vector<vector<int>>m,int i,int j,int n,vector<string>&ans,string temp)
    {
        if(m[n-1][n-1]==0)return;
        if(i==n-1 && j==n-1)
        {
            ans.push_back(temp);
            return;
        }
        
        if(i<0 || j<0 || i>=n || j>=n)
        return;
        
        
        if(m[i][j]==0)
        return;
        
        m[i][j]=0;
        f(m,i,j-1,n,ans,temp+'L');
        f(m,i,j+1,n,ans,temp+'R');
        f(m,i-1,j,n,ans,temp+'U');
        f(m,i+1,j,n,ans,temp+'D');
         
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string>ans;
        string temp;
        
        f(m,0,0,n,ans,temp);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends